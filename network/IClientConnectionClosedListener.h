//
// Created by kir on 25.06.19.
//

#ifndef WEBSOCKETS_ICLIENTCONNECTIONCLOSEDLISTENER_H
#define WEBSOCKETS_ICLIENTCONNECTIONCLOSEDLISTENER_H

class TcpSocket;

class IClientConnectionClosedListener
{
public:

    virtual void onConnectionClosed(TcpSocket *client) = 0;
};


#endif //WEBSOCKETS_ICLIENTCONNECTIONCLOSEDLISTENER_H
