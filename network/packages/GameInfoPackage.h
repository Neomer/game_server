//
// Created by vinokurov on 27.06.2019.
//

#ifndef WEBSOCKETS_GAMEINFOPACKAGE_H
#define WEBSOCKETS_GAMEINFOPACKAGE_H

#include "Package.h"

class Game;

class GameInfoPackage : public Package
{
public:
    GameInfoPackage(const Game *game);

    void compile(nlohmann::json &json) const override;

private:
    const Game *_game;
};


#endif //WEBSOCKETS_GAMEINFOPACKAGE_H
