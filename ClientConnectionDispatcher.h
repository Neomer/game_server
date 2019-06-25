//
// Created by kir on 25.06.19.
//

#ifndef WEBSOCKETS_CLIENTCONNECTIONDISPATCHER_H
#define WEBSOCKETS_CLIENTCONNECTIONDISPATCHER_H

#include <vector>
#include <mutex>
#include "IConnectionAcceptedListener.h"
#include "IClientDataReadyListener.h"
#include "IClientConnectionClosedListener.h"

class ClientConnectionDispatcher : public IConnectionAcceptedListener,
        public IClientDataReadyListener,
        public IClientConnectionClosedListener
{
public:
    ClientConnectionDispatcher();

    ~ClientConnectionDispatcher();

    void onConnectionAccepted(Client *client) override;

    void onDataReady(Client *client, nlohmann::json &json) override;

    void onConnectionClosed(Client *client) override;

private:
    std::mutex _clientsVectorMutex;
    std::vector<Client *> _clients;
};


#endif //WEBSOCKETS_CLIENTCONNECTIONDISPATCHER_H
