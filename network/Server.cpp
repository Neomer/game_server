//
// Created by kir on 24.06.19.
//
#include <functional>
#include <iostream>
#include "Sockets.h"
#include "Server.h"
#include "TcpSocket.h"
#include "IConnectionAcceptedListener.h"
#include "../Logger.h"

using namespace std::string_literals;

Server::Server() :
    _listeningRun{ false },
    _connectionAcceptedListener{ nullptr }
{

}

void Server::listen(std::string_view ip, uint16_t port)
{
    Logger::getInstace().log("Server::listen()");
    _socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if(bind(_socketDescriptor, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        throw std::runtime_error("Socket bind failed!");
    }
    _listeningRun = true;
    _connectionAwaitThread = std::thread(std::bind(&Server::connectionAwaitingProc, this));
    _connectionAwaitThread.detach();
}

void Server::connectionAwaitingProc()
{
    Logger::getInstace().log("Server::connectionAwaitingProc() - start thread...");
    ::listen(_socketDescriptor, 10);
    while (_listeningRun) {
        auto socket = accept(_socketDescriptor, nullptr, nullptr);
        if (_connectionAcceptedListener != nullptr && socket > 0 && socket != INVALID_SOCKET) {
            _connectionAcceptedListener->onConnectionAccepted(this, createSocket(socket));
        }
    }
    Logger::getInstace().log("Server::connectionAwaitingProc() - Thread finished");
}

void Server::setOnConnectionAcceptedListener(IConnectionAcceptedListener *listener)
{
    _connectionAcceptedListener = listener;
}

Server::~Server()
{
    close();
}

void Server::close() {
    _listeningRun = false;

#ifdef _WIN32
    shutdown(_socketDescriptor, 0);
    closesocket(_socketDescriptor);
#endif

#ifdef __linux__
    // TODO: Закрытие сокета для Linux
#endif

    if (_connectionAwaitThread.joinable())  {
        _connectionAwaitThread.join();
    }

}

TcpSocket *Server::createSocket(int clientSocket) {
    return new TcpSocket(clientSocket);
}
