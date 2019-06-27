//
// Created by vinokurov on 27.06.2019.
//

#ifndef WEBSOCKETS_OBSERVER_H
#define WEBSOCKETS_OBSERVER_H

#include "../network/TcpSocket.h"

class Package;

class Observer {
public:
    explicit Observer(TcpSocket *socket);

    void send(Package *package);

private:
    TcpSocket *_socket;

};


#endif //WEBSOCKETS_OBSERVER_H
