#include <iostream>
#include "Server.h"
#include "ClientConnectionDispatcher.h"
#include "Sockets.h"
#include "Logger.h"

#include "game/Card.h"
#include "game/CardMetadataProvider.h"
#include "game/HandTakableCard.h"

int main()
{
#ifdef _WIN32
    WSADATA wsaData;
    if (WSAStartup(WINSOCK_VERSION, &wsaData)) {
        throw std::runtime_error("Winsock initialization failed!");
    }
#endif

    CardMetadataProvider::getInstance().init();

    ClientConnectionDispatcher dispatcher;

    Server srv;
    srv.setOnConnectionAcceptedListener(&dispatcher);
    srv.listen("0.0.0.0", 11555);

    char cmd;
    while (true)
    {
        std::cin >> cmd;
        std::cout << cmd  << std::endl;
        if (cmd == 'q') {
            break;
        }
    }

    dispatcher.close();

#ifdef _WIN32
    WSACleanup();
#endif
    return 0;
}