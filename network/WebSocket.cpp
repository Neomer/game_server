//
// Created by vinokurov on 27.06.2019.
//

#include "WebSocket.h"
#include "../modules/PicoSHA2/picosha2.h"
#include "../core/string_functions.h"

using namespace std::string_literals;

WebSocket::WebSocket(int socket) :
    TcpSocket(socket),
    _state{ ChannelState::Open }
{

}

WebSocket::~WebSocket() {

}

void WebSocket::write(nlohmann::json &json) {
    TcpSocket::write(json);
}

void WebSocket::prepareRawData(char **buffer, size_t *size) {
    if (_state == ChannelState::Ready) {

    } else {
        auto securityKeyIdx = strstr(*buffer, "Sec-WebSocket-Key:");
        if (securityKeyIdx != nullptr) {
            securityKeyIdx += 18;
            std::string securityKey(securityKeyIdx, strstr(securityKeyIdx, "\r\n") - securityKeyIdx);
            trim(securityKey);
        }

        *size = 0;
        auto msg = "HTTP/1.1 101 Web Socket Protocol Handshake\r\n"
                   "Upgrade: WebSocket\r\n"
                   "Connection: Upgrade\r\n"
                   "WebSocket-Origin: http://localhost:11555\r\n"
                   "WebSocket-Location: ws://localhost:11555/demo\r\n\r\n";
        TcpSocket::write(msg, strlen(msg));
        _state = ChannelState::Ready;
    }
}

