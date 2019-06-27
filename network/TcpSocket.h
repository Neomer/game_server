//
// Created by kir on 25.06.19.
//

#ifndef WEBSOCKETS_TCPSOCKET_H
#define WEBSOCKETS_TCPSOCKET_H

#include <functional>
#include <thread>
#include <atomic>
#include <condition_variable>
#include <queue>
#include "../json.hpp"

class IClientDataReadyListener;

class IClientConnectionClosedListener;

class TcpSocket
{
public:
    TcpSocket(int socket);

    virtual ~TcpSocket();

    virtual void write(nlohmann::json &json);

    void close();

    void setOnDataReadyListener(IClientDataReadyListener *listener);

    void setOnConnectionClosedListener(IClientConnectionClosedListener *listener);

protected:
    virtual void prepareRawData(char **buffer);

private:
    int _socket;
    IClientDataReadyListener *_dataReadyListener;
    IClientConnectionClosedListener *_connectionClosedListener;

    std::queue<nlohmann::json> _dataForSend, _dataForSendCopy;
    std::mutex _queueMutex;

    std::atomic_bool _run;
    std::thread _readThread, _writeThread;
    std::condition_variable _writeCondVar;

    void readDataProc();
    void writeDataProc();

};


#endif //WEBSOCKETS_TCPSOCKET_H
