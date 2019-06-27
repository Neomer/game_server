//
// Created by vinokurov on 27.06.2019.
//

#ifndef WEBSOCKETS_GAME_H
#define WEBSOCKETS_GAME_H

#include <vector>
#include <string_view>

#include "Player.h"
#include "Observer.h"
#include "../network/Server.h"
#include "../network/IConnectionAcceptedListener.h"
#include "../network/IClientConnectionClosedListener.h"
#include "../network/IClientDataReadyListener.h"
#include "GameConfig.h"

class Game :
        public IConnectionAcceptedListener,
        public IClientConnectionClosedListener,
        public IClientDataReadyListener
{
public:
    explicit Game(GameConfig &&gameConfig);

    ~Game();

    void begin();

    Player *createPlayer();

    void onConnectionAccepted(const Server *server, TcpSocket *client) override;

    void onConnectionClosed(TcpSocket *client) override;

    void onDataReady(TcpSocket *client, nlohmann::json &json) override;

    const std::vector<Player *> &getPlayers() const;

    const std::vector<Observer *> &getObservers() const;

    const GameConfig &getGameConfig() const;

private:
    std::vector<Player *> _players;
    std::vector<Observer *> _observers;
    Server *_playersServer, *_observersServer;

    GameConfig _gameConfig;

    void sendGameInfo();

    void sendPackageToObservers(Package *package);
};


#endif //WEBSOCKETS_GAME_H
