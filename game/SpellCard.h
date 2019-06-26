//
// Created by kir on 26.06.19.
//

#ifndef WEBSOCKETS_SPELLCARD_H
#define WEBSOCKETS_SPELLCARD_H

#include "HandTakableCard.h"

class SpellCard : public Card
{

};

class SpellCardMetadata : public HandTakableCardMetadata
{
public:
    SpellCardMetadata();

    CardType getCardType() const final;
};


#endif //WEBSOCKETS_SPELLCARD_H
