//
// Created by kir on 26.06.19.
//

#ifndef WEBSOCKETS_WEAPONCARD_H
#define WEBSOCKETS_WEAPONCARD_H

#include "HandTakableCard.h"

class WeaponCard : public Card
{

};

class WeaponCardMetadata : public HandTakableCardMetadata
{
public:
    WeaponCardMetadata();

    CardType getCardType() const override;

};


#endif //WEBSOCKETS_WEAPONCARD_H
