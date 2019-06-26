//
// Created by kir on 25.06.19.
//

#include <functional>
#include <iostream>
#include <unistd.h>
#include <chrono>
#include "json.hpp"
#include "Sockets.h"
#include "TcpSocket.h"
#include "IClientDataReadyListener.h"
#include "IClientConnectionClosedListener.h"

#define BUFFER_SIZE     1024

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
    std::cout << "TcpSocket::TcpSocketket()" << std::endl;
    _run = false;
}

void TcpSocket::readDataProc()
{
    if (_socket < 0) {
        return;
    }
    std::cout << "read thread start" << std::endl;
    char buffer[BUFFER_SIZE], *buffer_ptr;
    while (_run.load()) {
        std::cout << "waiting for clent data..." << std::endl;
#ifdef _WIN32
        auto len = recv(_socket, buffer, BUFFER_SIZE, 0);
#endif
#ifdef __linux__
        auto len = read(_socket, buffer, BUFFER_SIZE);
#endif
        if (!len) {
            std::cout << "Connection closed!" << std::endl;
            if (_connectionClosedListener != nullptr) {
                _connectionClosedListener->onConnectionClosed(this);
            }
            break;
        }
        if (len < 0) {
            std::cout << "Wrong length" << std::endl;
        } else {
            buffer_ptr = buffer;
            auto start = std::chrono::steady_clock::now();
            std::cout << len << " bytes received" << std::endl;
            if (_dataReadyListener != nullptr) {
                try {
                    buffer[len] = 0;
                    prepareRawData(&buffer_ptr);
                    nlohmann::json jDoc = nlohmann::json::parse(buffer_ptr);
                    _dataReadyListener->onDataReady(this, jDoc);
                }
                catch (nlohmann::json::parse_error &ex)
                {
                    std::cout << "Json parsing error: " << ex.what() << std::endl;
                }
                auto end = std::chrono::steady_clock::now();
                std::cout << "Package process time: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " mcsec" << std::endl;
            }
        }
    }
    std::cout << "read thread finished" << std::endl;
}


void TcpSocket::writeDataProc() {
    if (_socket < 0) {
        return;
    }
    std::mutex lockMtx;
    std::unique_lock lock(lockMtx);
    std::cout << "write thread start" << std::endl;
    while (_run.load()) {
        _writeCondVar.wait(lock);
        if (!_dataForSend.empty()) {
            std::lock_guard lock(_queueMutex);
            _dataForSendCopy.swap(_dataForSend);
        }
        while (!_dataForSendCopy.empty()) {
            auto message = _dataForSendCopy.front().dump();
#ifdef _WIN32
            auto sent = send(_socket, message.c_str(), message.size(), 0);
#endif

#ifdef __linux__
            auto sent = write(_socket, message.c_str(), message.size());
#endif
            _dataForSendCopy.pop();
        }
    }
    std::cout << "write thread finished" << std::endl;
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

void TcpSocket::prepareRawData(char **buffer) {
    *buffer = strstr(*buffer, "\r\n\r\n") + 4;
}

