//
// Created by vinokurov on 27.06.2019.
//

#include "Game.h"
#include "../Logger.h"
#include "../network/WebSocketServer.h"

Game::Game(GameConfig &&gameConfig) :
    _gameConfig{ std::move(gameConfig) },
    _observersServer{ new WebSocketServer{} },
    _playersServer{ new Server{} }
{

}

Game::~Game() {
    _playersServer->close();
    delete _playersServer;

    _observersServer->close();
    delete _observersServer;
}

Player *Game::createPlayer() {
    return nullptr;
}

void Game::onConnectionAccepted(const Server *server, TcpSocket *client) {
    if (server == _playersServer) {
        Logger::getInstace().log("New player joined!");
        auto player = new Player(client);
        _players.push_back(player);
    } else if (server == _observersServer) {
        Logger::getInstace().log("New observer joined!");
        auto observer = new Observer(client);
        _observers.push_back(observer);
    }
}

void Game::begin() {
    _playersServer->setOnConnectionAcceptedListener(this);
    _playersServer->listen("0.0.0.0", 11556);

    _observersServer->setOnConnectionAcceptedListener(this);
    _observersServer->listen("0.0.0.0", 11555);
}

const std::vector<Player *> &Game::getPlayers() const {
    return _players;
}

const std::vector<Observer *> &Game::getObservers() const {
    return _observers;
}

const GameConfig &Game::getGameConfig() const {
    return _gameConfig;
}

