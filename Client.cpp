//
// Created by kir on 25.06.19.
//
#include <sys/socket.h>
#include <functional>
#include <iostream>
#include <unistd.h>
#include <chrono>
#include "json.hpp"
#include "Client.h"
#include "IClientDataReadyListener.h"
#include "IClientConnectionClosedListener.h"

#define BUFFER_SIZE     1024

Client::Client(int socket) :
    _socket{ socket },
    _run{ true },
    _dataReadyListener{ nullptr }, _connectionClosedListener{ nullptr },
    _readThread{ std::bind(&Client::readDataProc, this) }
{
    _readThread.detach();
}

Client::~Client()
{
    std::cout << "Client::~Client()" << std::endl;
    _run = false;
}

void Client::readDataProc()
{
    if (_socket < 0) {
        return;
    }
    std::cout << "read thread start" << std::endl;
    char buffer[BUFFER_SIZE];
    while (_run.load()) {
        std::cout << "waiting for clent data..." << std::endl;
        auto len = read(_socket, buffer, BUFFER_SIZE);
        if (!len) {
            std::cout << "Connection closed!" << std::endl;
            if (_connectionClosedListener != nullptr) {
                _connectionClosedListener->onConnectionClosed(this);
            }
            break;
        }
        auto start = std::chrono::steady_clock::now();
        std::cout << len << " bytes received" << std::endl;
        if (_dataReadyListener != nullptr) {
            try {
                buffer[len] = 0;
                std::string sData = strstr(buffer, "\r\n\r\n");
                nlohmann::json jDoc = nlohmann::json::parse(sData);
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
    std::cout << "read thread finished" << std::endl;
}

void Client::setOnDataReadyListener(IClientDataReadyListener *listener)
{
    _dataReadyListener = listener;
}

void Client::setOnConnectionClosedListener(IClientConnectionClosedListener *listener)
{
    _connectionClosedListener = listener;
}

