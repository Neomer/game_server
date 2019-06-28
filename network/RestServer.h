//
// Created by vinokurov on 28.06.2019.
//

#ifndef WEBSOCKETS_RESTSERVER_H
#define WEBSOCKETS_RESTSERVER_H

#include "Server.h"

class RestServer : public Server {
public:
    ~RestServer() override;

protected:
    TcpSocket *createSocket(int clientSocket) override;
};


#endif //WEBSOCKETS_RESTSERVER_H
