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

private:
    enum class ChannelState {
        Open,   // Подключение открыто, но клиент не прислал запрос на установку канала связи
        Ready   // Канал связи открыт
    };
    ChannelState _state;

    enum class DataType
    {
        Data,
        Text,
        Binary
    };

protected:
    void prepareRawData(char **buffer, size_t *size) override;
};


#endif //WEBSOCKETS_WEBSOCKET_H
