//
// Created by kir on 25.06.19.
//

#include <string>
#include <functional>
#include <iostream>
#include <unistd.h>
#include <iomanip>
#include <chrono>
#include "../json.hpp"
#include "Sockets.h"
#include "TcpSocket.h"
#include "IClientDataReadyListener.h"
#include "IClientConnectionClosedListener.h"
#include "../Logger.h"
#include "packages/Package.h"

#define BUFFER_SIZE     1024

using namespace std::literals;

TcpSocket::TcpSocket(int socket) :
    _socket{ socket },
    _run{ true },
    _dataReadyListener{ nullptr }, _connectionClosedListener{ nullptr },
    _readThread{ std::bind(&TcpSocket::readDataProc, this) },
    _writeThread{ std::bind(&TcpSocket::writeDataProc, this) }
{
    _readThread.detach();
    _writeThread.detach();
}

TcpSocket::~TcpSocket()
{
    Logger::getInstace().log("TcpSocket::~TcpSocket()");
    _run = false;
}

void TcpSocket::readDataProc()
{
    if (_socket < 0) {
        return;
    }
    Logger::getInstace().log("read thread start");
    char buffer[BUFFER_SIZE], *buffer_ptr;
    while (_run.load()) {
        Logger::getInstace().log("waiting for client data...");
#ifdef _WIN32
        auto len = recv(_socket, buffer, BUFFER_SIZE, 0);
#endif
#ifdef __linux__
        auto len = read(_socket, buffer, BUFFER_SIZE);
#endif
        if (!len) {
            Logger::getInstace().log("Connection closed!");
            if (_connectionClosedListener != nullptr) {
                _connectionClosedListener->onConnectionClosed(this);
            }
            break;
        }
        if (len < 0) {
            Logger::getInstace().log("Wrong length!");
        } else {
            buffer_ptr = buffer;
            auto start = std::chrono::steady_clock::now();
            Logger::getInstace().log(std::to_string(len) + " bytes received");
            if (_dataReadyListener != nullptr) {
                try {
                    size_t size = len;
                    prepareRawData(&buffer_ptr, &size);
                    if (size > 0) {
                        buffer[size] = 0;
                        nlohmann::json jDoc = nlohmann::json::parse(buffer_ptr);
                        _dataReadyListener->onDataReady(this, jDoc);
                    }
                }
                catch (nlohmann::json::parse_error &ex)
                {
                    Logger::getInstace().log("Json parsing error: "s + ex.what());
                }
                auto end = std::chrono::steady_clock::now();
                Logger::getInstace().log("Package process time: "s + std::to_string(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()) + " mcsec");
            } else {
                Logger::getInstace().log("No data listener");
            }
        }
    }
    Logger::getInstace().log("read thread finished");
}


void TcpSocket::writeDataProc() {
    if (_socket < 0) {
        return;
    }
    std::mutex lockMtx;
    std::unique_lock uniq(lockMtx);
    Logger::getInstace().log("write thread start");
    while (_run.load()) {
        _writeCondVar.wait(uniq);
        if (!_dataForSend.empty()) {
            std::lock_guard lock(_queueMutex);
            _dataForSendCopy.swap(_dataForSend);
        }
        while (!_dataForSendCopy.empty()) {
            auto message = _dataForSendCopy.front().dump();
            write(message.c_str(), message.size());
            _dataForSendCopy.pop();
        }
    }
    Logger::getInstace().log("write thread finished");
}

void TcpSocket::setOnDataReadyListener(IClientDataReadyListener *listener)
{
    _dataReadyListener = listener;
}

void TcpSocket::setOnConnectionClosedListener(IClientConnectionClosedListener *listener)
{
    _connectionClosedListener = listener;
}

void TcpSocket::write(nlohmann::json &json) {
    {
        std::lock_guard lock(_queueMutex);
        _dataForSend.push(std::move(json));
    }
    _writeCondVar.notify_one();
}

void TcpSocket::prepareRawData(char **buffer, size_t *size) {

}

void TcpSocket::close()
{
    _run = false;
    _writeCondVar.notify_all();
    if (_readThread.joinable()) {
        _readThread.join();
    }
    if (_writeThread.joinable()) {
        _writeThread.join();
    }
}

void TcpSocket::write(Package *package) {
    if (package == nullptr) {
        return;
    }
    nlohmann::json json;
    package->compile(json);
    write(json);

    delete package;
}

void TcpSocket::write(const char *data, size_t size) {
#ifdef _WIN32
    send(_socket, data, size, 0);
#endif

#ifdef __linux__
    auto sent = ::write(_socket, data, size);
#endif
}
