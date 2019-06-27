//
// Created by vinokurov on 27.06.2019.
//

#include "WebSocket.h"

WebSocket::WebSocket(int socket) :
    TcpSocket(socket)
{

}

WebSocket::~WebSocket() {

}

void WebSocket::write(nlohmann::json &json) {
    TcpSocket::write(json);
}

void WebSocket::prepareRawData(char **buffer) {
    TcpSocket::prepareRawData(buffer);
}

