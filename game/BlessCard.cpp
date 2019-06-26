//
// Created by kir on 26.06.19.
//

#include "BlessCard.h"

BlessCardMetadata::BlessCardMetadata() :
        HandTakableCardMetadata()
{

}

CardMetadata::CardType BlessCardMetadata::getCardType() const
{
    return CardMetadata::CardType::Blessing;
}
