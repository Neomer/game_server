cmake_minimum_required(VERSION 3.14)
project(websockets)

set(CMAKE_CXX_STANDARD 17)

add_executable(websockets main.cpp Server.cpp Server.h IConnectionAcceptedListener.cpp IConnectionAcceptedListener.h ClientConnectionDispatcher.cpp ClientConnectionDispatcher.h TcpSocket.cpp TcpSocket.h IClientDataReadyListener.cpp IClientDataReadyListener.h IClientConnectionClosedListener.cpp IClientConnectionClosedListener.h Sockets.h Logger.cpp Logger.h game/cards/Role.cpp game/cards/Role.h game/cards/Card.cpp game/cards/Card.h game/cards/Metadata.cpp game/cards/Metadata.h game/cards/HealCard.cpp game/cards/HealCard.h game/CardMetadataProvider.cpp game/CardMetadataProvider.h game/cards/EvilDetection.cpp game/cards/EvilDetection.h game/cards/SpellCard.cpp game/cards/SpellCard.h game/cards/FindTraps.cpp game/cards/FindTraps.h game/cards/HandTakableCard.cpp game/cards/HandTakableCard.h game/cards/Divination.cpp game/cards/Divination.h game/cards/EnergyBolt.cpp game/cards/EnergyBolt.h game/cards/Amplification.cpp game/cards/Amplification.h game/cards/BlessCard.cpp game/cards/BlessCard.h game/cards/WeaponCard.cpp game/cards/WeaponCard.h game/cards/LongSword.cpp game/cards/LongSword.h game/cards/Sling.cpp game/cards/Sling.h game/cards/LightCrossbow.cpp game/cards/LightCrossbow.h)

SET(CMAKE_CXX_FLAGS -pthread)
if(WIN32)
    target_link_libraries(websockets wsock32 ws2_32)
endif()