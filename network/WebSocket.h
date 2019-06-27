//
// Created by vinokurov on 27.06.2019.
//

#ifndef WEBSOCKETS_WEBSOCKET_H
#define WEBSOCKETS_WEBSOCKET_H

#include "TcpSocket.h"

class WebSocket : public TcpSocket {
public:
    WebSocket(int socket);

    ~WebSocket() override;

    void write(nlohmann::json &json) override;

protected:
    void prepareRawData(char **buffer) override;
};


#endif //WEBSOCKETS_WEBSOCKET_H
