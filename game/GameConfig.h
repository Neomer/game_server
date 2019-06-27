//
// Created by vinokurov on 27.06.2019.
//

#ifndef WEBSOCKETS_GAMECONFIG_H
#define WEBSOCKETS_GAMECONFIG_H

#include <string>
#include <string_view>

class GameConfig {
public:

    const std::string &getGameKey() const;

    void setGameKey(std::string_view gameKey);

    const std::string &getModeratorKey() const;

    void setModeratorKey(std::string_view moderatorKey);

    int getMaxPlayersCount() const;

    void setMaxPlayersCount(int maxPlayersCount);

private:
    std::string _gameKey, _moderatorKey;
    int _maxPlayersCount;
};


#endif //WEBSOCKETS_GAMECONFIG_H
