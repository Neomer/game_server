//
// Created by vinokurov on 27.06.2019.
//

#include "GameConfig.h"

const std::string &GameConfig::getGameKey() const {
    return _gameKey;
}

void GameConfig::setGameKey(std::string_view gameKey) {
    _gameKey = gameKey;
}

const std::string &GameConfig::getModeratorKey() const {
    return _moderatorKey;
}

void GameConfig::setModeratorKey(std::string_view moderatorKey) {
    _moderatorKey = moderatorKey;
}

int GameConfig::getMaxPlayersCount() const {
    return _maxPlayersCount;
}

void GameConfig::setMaxPlayersCount(int maxPlayersCount) {
    _maxPlayersCount = maxPlayersCount;
}
