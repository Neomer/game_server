//
// Created by kir on 26.06.19.
//

#ifndef WEBSOCKETS_ROLE_H
#define WEBSOCKETS_ROLE_H

#include <string>

class Role
{
public:
    Role();

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getDescription() const;

    void setDescription(const std::string &description);

private:
    std::string _name, _description;
};


#endif //WEBSOCKETS_ROLE_H
