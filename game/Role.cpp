//
// Created by kir on 26.06.19.
//

#include "Role.h"

Role::Role()
{

}

const std::string &Role::getName() const
{
    return _name;
}

void Role::setName(const std::string &name)
{
    _name = name;
}

const std::string &Role::getDescription() const
{
    return _description;
}

void Role::setDescription(const std::string &description)
{
    _description = description;
}
