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

    void close();

    void onConnectionAccepted(const Server *server, TcpSocket *client) override;

    void onDataReady(TcpSocket *client, nlohmann::json &json) override;

    void onConnectionClosed(TcpSocket *client) override;

private:
    std::mutex _clientsVectorMutex;
    std::vector<TcpSocket *> _clients;
};


#endif //WEBSOCKETS_CLIENTCONNECTIONDISPATCHER_H
