//
// Created by vinokurov on 26.06.2019.
//

#ifndef WEBSOCKETS_SOCKETS_H
#define WEBSOCKETS_SOCKETS_H

#ifdef __linux__
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#endif

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>

#pragma comment(lib, "Ws2_32.lib")
#endif


#endif //WEBSOCKETS_SOCKETS_H
