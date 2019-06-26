cmake_minimum_required(VERSION 3.14)
project(websockets)

set(CMAKE_CXX_STANDARD 17)

add_executable(websockets main.cpp Server.cpp Server.h IConnectionAcceptedListener.cpp IConnectionAcceptedListener.h ClientConnectionDispatcher.cpp ClientConnectionDispatcher.h TcpSocket.cpp TcpSocket.h IClientDataReadyListener.cpp IClientDataReadyListener.h IClientConnectionClosedListener.cpp IClientConnectionClosedListener.h Sockets.h Logger.cpp Logger.h)

SET(CMAKE_CXX_FLAGS -pthread)
if(WIN32)
    target_link_libraries(websockets wsock32 ws2_32)
endif()