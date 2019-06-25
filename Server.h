//
// Created by kir on 24.06.19.
//

#ifndef WEBSOCKETS_SERVER_H
#define WEBSOCKETS_SERVER_H

#include <thread>
#include <string_view>
#include <inttypes.h>
#include <atomic>

class IConnectionAcceptedListener;

class Server
{
public:
    Server();

    virtual ~Server();

    void listen(std::string_view ip, uint16_t port);

    void setOnConnectionAcceptedListener(IConnectionAcceptedListener *listener);

private:
    int _socketDescriptor;
    IConnectionAcceptedListener *_connectionAcceptedListener;

    std::thread _connectionAwaitThread;
    std::atomic_bool _listeningRun;
    void connectionAwaitingProc();

};


#endif //WEBSOCKETS_SERVER_H
