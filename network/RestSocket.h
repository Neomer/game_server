//
// Created by vinokurov on 28.06.2019.
//

#ifndef WEBSOCKETS_RESTSOCKET_H
#define WEBSOCKETS_RESTSOCKET_H

#include "TcpSocket.h"

class RestSocket : public TcpSocket {
public:
    RestSocket(int socket);

    ~RestSocket() override;

protected:
    void prepareRawData(char **buffer, size_t *size) override;
};


#endif //WEBSOCKETS_RESTSOCKET_H
