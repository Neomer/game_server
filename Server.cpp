//
// Created by kir on 24.06.19.
//
#include <functional>
#include <iostream>
#include "Sockets.h"
#include "Server.h"
#include "TcpSocket.h"
#include "IConnectionAcceptedListener.h"

Server::Server() :
    _listeningRun{ false },
    _connectionAcceptedListener{ nullptr }
{

}

void Server::listen(std::string_view ip, uint16_t port)
{
    std::cout << "Server::listen()" << std::endl;
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
    std::cout << "Server::connectionAwaitingProc() - start thread..." << std::endl;
    ::listen(_socketDescriptor, 10);
    while (_listeningRun) {
        auto socket = accept(_socketDescriptor, NULL, NULL);
        if (_connectionAcceptedListener != nullptr && socket >= 0) {
            _connectionAcceptedListener->onConnectionAccepted(new TcpSocket(socket));
        }
    }
    std::cout << "Server::connectionAwaitingProc() - Thread finished" << std::endl;
}

void Server::setOnConnectionAcceptedListener(IConnectionAcceptedListener *listener)
{
    _connectionAcceptedListener = listener;
}

Server::~Server()
{
    _listeningRun = false;
    if (_connectionAwaitThread.joinable())  {
        _connectionAwaitThread.join();
    }
}
