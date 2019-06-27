//
// Created by vinokurov on 27.06.2019.
//

#include "GameInfoPackage.h"
#include "../../game/Game.h"

GameInfoPackage::GameInfoPackage(const Game *game) :
    Package(),
    _game{ game }
{

}

void GameInfoPackage::compile(nlohmann::json &json) const {
    json["config"] = nlohmann::json::object();
    json["config"]["max_players"] = _game->getGameConfig().getMaxPlayersCount();
    json["state"] = nlohmann::json::object();
    json["state"]["current_players"] = _game->getPlayers().size();
    json["state"]["current_spectators"] = _game->getObservers().size();
}
