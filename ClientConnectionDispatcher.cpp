//
// Created by kir on 25.06.19.
//

#include <sys/socket.h>
#include <algorithm>
#include <iostream>
#include "ClientConnectionDispatcher.h"
#include "Client.h"

ClientConnectionDispatcher::ClientConnectionDispatcher()
{

}

ClientConnectionDispatcher::~ClientConnectionDispatcher()
{

}

void ClientConnectionDispatcher::onConnectionAccepted(Client *client)
{
    std::lock_guard lock(_clientsVectorMutex);
    _clients.push_back(client);
    client->setOnConnectionClosedListener(this);
    client->setOnDataReadyListener(this);
    std::cout << "New client pushed to pool. Total connections: " << _clients.size() << std::endl;
}

void ClientConnectionDispatcher::onDataReady(Client *client, nlohmann::json &json)
{
    std::cout << "Data: " << json << std::endl;
}

void ClientConnectionDispatcher::onConnectionClosed(Client *client)
{
    std::lock_guard lock(_clientsVectorMutex);
    auto it = std::remove(_clients.begin(), _clients.end(), client);
    std::for_each(it, _clients.end(), [&](Client *client) {
        delete client;
    });
    _clients.erase(it, _clients.end());
    std::cout << "Client removed from pool. Total connections: " << _clients.size() << std::endl;
}
