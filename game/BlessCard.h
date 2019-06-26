//
// Created by kir on 26.06.19.
//

#ifndef WEBSOCKETS_BLESSCARD_H
#define WEBSOCKETS_BLESSCARD_H

#include "HandTakableCard.h"

class BlessCard : public Card
{
public:
    BlessCard();
};

class BlessCardMetadata : public HandTakableCardMetadata
{
public:
    BlessCardMetadata();

    CardType getCardType() const final;
};


#endif //WEBSOCKETS_BLESSCARD_H
