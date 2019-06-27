//
// Created by vinokurov on 27.06.2019.
//

#include "WebSocketServer.h"
#include "WebSocket.h"

WebSocketServer::WebSocketServer() {

}

WebSocketServer::~WebSocketServer() {

}

TcpSocket *WebSocketServer::createSocket(int clientSocket) {
    return new WebSocket(clientSocket);
}
