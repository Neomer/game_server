//
// Created by kir on 26.06.19.
//

#ifndef WEBSOCKETS_ROLE_H
#define WEBSOCKETS_ROLE_H

#include <string>
#include "../../json.hpp"

class Role
{
public:
    Role();

    virtual const std::string &getName() const = 0;

    virtual const std::string &getDescription() const = 0;


private:
    std::string _name, _description;
};


#endif //WEBSOCKETS_ROLE_H
