//
// Created by kir on 26.06.19.
//

#include "SpellCard.h"

CardMetadata::CardType SpellCardMetadata::getCardType() const
{
    return CardMetadata::CardType::Spell;
}

SpellCardMetadata::SpellCardMetadata() :
        HandTakableCardMetadata()
{

}
