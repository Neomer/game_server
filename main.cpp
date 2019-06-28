#include "network/Sockets.h"
#include <string>
#include <iostream>
#include "Logger.h"
#include "game/CardMetadataProvider.h"
#include "game/Game.h"

int main()
{
#ifdef _WIN32
    WSADATA wsaData;
    if (WSAStartup(WINSOCK_VERSION, &wsaData)) {
        throw std::runtime_error("Winsock initialization failed!");
    }
#endif

    try {
        // Инициализируем метаданные карт
        CardMetadataProvider::getInstance().init();

        GameConfig cfg;
        cfg.setGameKey("hello world");
        cfg.setModeratorKey("god mode");
        cfg.setMaxPlayersCount(3);

        Game game(std::move(cfg));
        game.begin();

        char cmd;
        while (true)
        {
            std::cin >> cmd;
            std::cout << cmd  << std::endl;
            if (cmd == 'q') {
                break;
            }
        }
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

#ifdef _WIN32
    WSACleanup();
#endif
    return 0;
}