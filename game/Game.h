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
#include "GameConfig.h"

class Game : public IConnectionAcceptedListener {
public:
    explicit Game(GameConfig &&gameConfig);

    ~Game();

    void begin();

    Player *createPlayer();

    void onConnectionAccepted(const Server *server, TcpSocket *client) override;

    const std::vector<Player *> &getPlayers() const;

    const std::vector<Observer *> &getObservers() const;

    const GameConfig &getGameConfig() const;

private:
    std::vector<Player *> _players;
    std::vector<Observer *> _observers;
    Server *_playersServer, *_observersServer;

    GameConfig _gameConfig;
};


#endif //WEBSOCKETS_GAME_H
