//
// Created by vinokurov on 28.06.2019.
//

#include "RestServer.h"
#include "RestSocket.h"

RestServer::~RestServer() {

}

TcpSocket *RestServer::createSocket(int clientSocket) {
    return new RestSocket(clientSocket);
}
