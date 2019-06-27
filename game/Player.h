//
// Created by vinokurov on 27.06.2019.
//

#ifndef WEBSOCKETS_PLAYER_H
#define WEBSOCKETS_PLAYER_H

#include "../network/TcpSocket.h"
#include "CardDeckOwner.h"

class Player : public CardDeckOwner {
public:
    explicit Player(TcpSocket *socket);

private:
    TcpSocket *_socket;
};


#endif //WEBSOCKETS_PLAYER_H
