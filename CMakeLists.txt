cmake_minimum_required(VERSION 3.14)
project(websockets)

set(CMAKE_CXX_STANDARD 17)

add_executable(websockets main.cpp Server.cpp Server.h IConnectionAcceptedListener.cpp IConnectionAcceptedListener.h ClientConnectionDispatcher.cpp ClientConnectionDispatcher.h Client.cpp Client.h IClientDataReadyListener.cpp IClientDataReadyListener.h IClientConnectionClosedListener.cpp IClientConnectionClosedListener.h)

SET(CMAKE_CXX_FLAGS -pthread)