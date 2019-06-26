//
// Created by kir on 26.06.19.
//

#include "WeaponCard.h"

CardMetadata::CardType WeaponCardMetadata::getCardType() const
{
    return CardType::Weapon;
}

WeaponCardMetadata::WeaponCardMetadata() :
        HandTakableCardMetadata()
{

}
