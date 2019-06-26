//
// Created by kir on 26.06.19.
//

#ifndef WEBSOCKETS_HANDTAKABLECARD_H
#define WEBSOCKETS_HANDTAKABLECARD_H

#include "Card.h"

class HandTakableCardMetadata : public CardMetadata
{
public:
    HandTakableCardMetadata();

    virtual bool isBeginnerLevel() const = 0;
};


#endif //WEBSOCKETS_HANDTAKABLECARD_H
