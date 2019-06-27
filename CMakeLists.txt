cmake_minimum_required(VERSION 3.14)
project(websockets)

set(CMAKE_CXX_STANDARD 17)

add_executable(websockets main.cpp network/Server.cpp network/Server.h network/IConnectionAcceptedListener.h network/ClientConnectionDispatcher.cpp network/ClientConnectionDispatcher.h network/TcpSocket.cpp network/TcpSocket.h network/IClientDataReadyListener.h network/IClientConnectionClosedListener.h network/Sockets.h Logger.cpp Logger.h game/cards/Role.cpp game/cards/Role.h game/cards/Card.cpp game/cards/Card.h game/cards/Metadata.cpp game/cards/Metadata.h game/cards/HealCard.cpp game/cards/HealCard.h game/CardMetadataProvider.cpp game/CardMetadataProvider.h game/cards/EvilDetection.cpp game/cards/EvilDetection.h game/cards/SpellCard.cpp game/cards/SpellCard.h game/cards/FindTraps.cpp game/cards/FindTraps.h game/cards/HandTakableCard.cpp game/cards/HandTakableCard.h game/cards/Divination.cpp game/cards/Divination.h game/cards/EnergyBolt.cpp game/cards/EnergyBolt.h game/cards/Amplification.cpp game/cards/Amplification.h game/cards/BlessCard.cpp game/cards/BlessCard.h game/cards/WeaponCard.cpp game/cards/WeaponCard.h game/cards/LongSword.cpp game/cards/LongSword.h game/cards/Sling.cpp game/cards/Sling.h game/cards/LightCrossbow.cpp game/cards/LightCrossbow.h game/Player.cpp game/Player.h game/CardDeckOwner.cpp game/CardDeckOwner.h game/Game.cpp game/Game.h core/InfinityVector.cpp core/InfinityVector.h game/Observer.cpp game/Observer.h game/GameConfig.cpp game/GameConfig.h network/WebSocket.cpp network/WebSocket.h network/WebSocketServer.cpp network/WebSocketServer.h)

SET(CMAKE_CXX_FLAGS -pthread)
if(WIN32)
    target_link_libraries(websockets wsock32 ws2_32)
endif()