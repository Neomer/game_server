//
// Created by kir on 25.06.19.
//

#ifndef WEBSOCKETS_ICONNECTIONACCEPTEDLISTENER_H
#define WEBSOCKETS_ICONNECTIONACCEPTEDLISTENER_H

class TcpSocket;

class Server;

class IConnectionAcceptedListener
{
public:

    virtual void onConnectionAccepted(const Server *server, TcpSocket *client) = 0;
};


#endif //WEBSOCKETS_ICONNECTIONACCEPTEDLISTENER_H
