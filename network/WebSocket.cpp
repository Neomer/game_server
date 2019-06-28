//
// Created by vinokurov on 27.06.2019.
//

#include <iostream>
#include "WebSocket.h"
#include "../modules/SHA256/picosha2.h"
#include "../modules/cppcodec/cppcodec/base64_rfc4648.hpp"
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
        std::cout << *buffer;
        auto securityKeyIdx = strstr(*buffer, "Sec-WebSocket-Key:");
        std::string unbasedKey;
        std::string basedAnswerKey;
        if (securityKeyIdx != nullptr) {
            securityKeyIdx += 18;
            std::string securityKey(securityKeyIdx, strstr(securityKeyIdx, "\r\n") - securityKeyIdx);
            trim(securityKey);
            unbasedKey = (reinterpret_cast<const char *>(cppcodec::base64_rfc4648::decode(securityKey).data()));
        }
        unbasedKey += "258EAFA5-E914-47DA-95CA-C5AB0DC85B11";
        char hashBuffer[256];
        memset(hashBuffer, 0, 256);
        picosha2::hash256(unbasedKey.begin(), unbasedKey.end(), std::begin(hashBuffer), std::end(hashBuffer), 256);
        basedAnswerKey = cppcodec::base64_rfc4648::encode(hashBuffer, 32);


        *size = 0;
        auto msg = "HTTP/1.1 101 Web Socket Protocol Handshake\r\n"
                   "Upgrade: WebSocket\r\n"
                   "Connection: Upgrade\r\n"s +
                   "Sec-WebSocket-Accept:" + basedAnswerKey + "\r\n" +
                   "WebSocket-Origin: http://localhost:11555\r\n"
                   "WebSocket-Location: ws://localhost:11555/demo\r\n\r\n";
        TcpSocket::write(msg.c_str(), msg.size());
        _state = ChannelState::Ready;
    }
}

