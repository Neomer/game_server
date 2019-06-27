//
// Created by kir on 25.06.19.
//

#include <string>
#include <algorithm>
#include <iostream>
#include "ClientConnectionDispatcher.h"
#include "TcpSocket.h"
#include "Sockets.h"
#include "../Logger.h"

using namespace std::string_literals;

ClientConnectionDispatcher::ClientConnectionDispatcher()
{

}

ClientConnectionDispatcher::~ClientConnectionDispatcher()
{

}

void ClientConnectionDispatcher::onConnectionAccepted(const Server *server, TcpSocket *client)
{
    std::lock_guard lock(_clientsVectorMutex);
    _clients.push_back(client);
    client->setOnConnectionClosedListener(this);
    client->setOnDataReadyListener(this);
    Logger::getInstace().log("New client pushed to pool. Total connections: "s + std::to_string(_clients.size()));
}

void ClientConnectionDispatcher::onDataReady(TcpSocket *client, nlohmann::json &json)
{
    Logger::getInstace().log("Data: " + json.dump());
}

void ClientConnectionDispatcher::onConnectionClosed(TcpSocket *client)
{
    std::lock_guard lock(_clientsVectorMutex);
    auto it = std::remove(_clients.begin(), _clients.end(), client);
    std::for_each(it, _clients.end(),
            [&](TcpSocket *client) -> void {
                client->close();
            });
    _clients.erase(it, _clients.end());
    Logger::getInstace().log("TcpSocket removed from pool. Total connections: "s + std::to_string(_clients.size()));
}

void ClientConnectionDispatcher::close() {
    std::for_each(_clients.begin(), _clients.end(),
            [&](TcpSocket *c) -> void {
                delete c;
            });
}
