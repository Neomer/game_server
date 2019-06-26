cmake_minimum_required(VERSION 3.14)
project(websockets)

set(CMAKE_CXX_STANDARD 17)

add_executable(websockets main.cpp Server.cpp Server.h IConnectionAcceptedListener.cpp IConnectionAcceptedListener.h ClientConnectionDispatcher.cpp ClientConnectionDispatcher.h TcpSocket.cpp TcpSocket.h IClientDataReadyListener.cpp IClientDataReadyListener.h IClientConnectionClosedListener.cpp IClientConnectionClosedListener.h Sockets.h Logger.cpp Logger.h game/Role.cpp game/Role.h game/Card.cpp game/Card.h game/Metadata.cpp game/Metadata.h game/HealCard.cpp game/HealCard.h game/CardMetadataProvider.cpp game/CardMetadataProvider.h game/EvilDetection.cpp game/EvilDetection.h game/SpellCard.cpp game/SpellCard.h game/FindTraps.cpp game/FindTraps.h game/HandTakableCard.cpp game/HandTakableCard.h game/Divination.cpp game/Divination.h game/EnergyBolt.cpp game/EnergyBolt.h game/Amplification.cpp game/Amplification.h game/BlessCard.cpp game/BlessCard.h game/WeaponCard.cpp game/WeaponCard.h game/LongSword.cpp game/LongSword.h game/Sling.cpp game/Sling.h game/LightCrossbow.cpp game/LightCrossbow.h)

SET(CMAKE_CXX_FLAGS -pthread)
if(WIN32)
    target_link_libraries(websockets wsock32 ws2_32)
endif()