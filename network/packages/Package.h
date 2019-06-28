//
// Created by vinokurov on 27.06.2019.
//

#ifndef WEBSOCKETS_PACKAGE_H
#define WEBSOCKETS_PACKAGE_H

#include "../../json.hpp"

class Package {
public:
    Package();

    virtual ~Package();

    virtual void compile(nlohmann::json &json) const = 0;

};


#endif //WEBSOCKETS_PACKAGE_H
