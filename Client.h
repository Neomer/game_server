//
// Created by kir on 25.06.19.
//

#ifndef WEBSOCKETS_CLIENT_H
#define WEBSOCKETS_CLIENT_H

#include <functional>
#include <thread>
#include <atomic>

class IClientDataReadyListener;

class IClientConnectionClosedListener;

class Client
{
public:
    Client(int socket);

    ~Client();

    void setOnDataReadyListener(IClientDataReadyListener *listener);

    void setOnConnectionClosedListener(IClientConnectionClosedListener *listener);

private:
    int _socket;
    IClientDataReadyListener *_dataReadyListener;
    IClientConnectionClosedListener *_connectionClosedListener;

    std::atomic_bool _run;
    std::thread _readThread;
    void readDataProc();

};


#endif //WEBSOCKETS_CLIENT_H
