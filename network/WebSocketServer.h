//
// Created by vinokurov on 27.06.2019.
//

#ifndef WEBSOCKETS_WEBSOCKETSERVER_H
#define WEBSOCKETS_WEBSOCKETSERVER_H

#include "Server.h"

class WebSocketServer : public Server
{
public:
    WebSocketServer();

    ~WebSocketServer() override;

protected:
    TcpSocket *createSocket(int clientSocket) override;
};


#endif //WEBSOCKETS_WEBSOCKETSERVER_H
