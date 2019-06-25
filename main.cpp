#include <iostream>
#include "Server.h"
#include "ClientConnectionDispatcher.h"

int main()
{
    ClientConnectionDispatcher dispatcher;

    Server srv;
    srv.setOnConnectionAcceptedListener(&dispatcher);
    srv.listen("0.0.0.0", 11555);


    char cmd;
    while (true)
    {
        std::cin >> cmd;
        std::cout << cmd  << std::endl;
        if (cmd == 'q') {
            break;
        }
    }

    return 0;
}