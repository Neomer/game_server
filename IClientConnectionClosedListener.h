//
// Created by kir on 25.06.19.
//

#ifndef WEBSOCKETS_ICLIENTCONNECTIONCLOSEDLISTENER_H
#define WEBSOCKETS_ICLIENTCONNECTIONCLOSEDLISTENER_H

class Client;

class IClientConnectionClosedListener
{
public:

    virtual void onConnectionClosed(Client *client) = 0;
};


#endif //WEBSOCKETS_ICLIENTCONNECTIONCLOSEDLISTENER_H
