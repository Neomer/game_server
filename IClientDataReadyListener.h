//
// Created by kir on 25.06.19.
//

#ifndef WEBSOCKETS_ICLIENTDATAREADYLISTENER_H
#define WEBSOCKETS_ICLIENTDATAREADYLISTENER_H

#include "json.hpp"

class TcpSocket;

class IClientDataReadyListener
{
public:

    virtual void onDataReady(TcpSocket *client, nlohmann::json &json) = 0;
};


#endif //WEBSOCKETS_ICLIENTDATAREADYLISTENER_H
