//
// Created by vinokurov on 28.06.2019.
//

#include "RestSocket.h"

RestSocket::~RestSocket() {

}

RestSocket::RestSocket(int socket) : TcpSocket(socket) {

}

void RestSocket::prepareRawData(char **buffer, size_t *size) {
    *buffer = strstr(*buffer, "\r\n\r\n") + 4;
}
