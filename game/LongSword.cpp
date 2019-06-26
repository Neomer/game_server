//
// Created by kir on 26.06.19.
//

#include "LongSword.h"

std::shared_ptr<Card> LongSwordMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new WeaponCard());
}

std::string_view LongSwordMetadata::getCardName() const
{
    return "Длинный меч";
}

bool LongSwordMetadata::isBeginnerLevel() const
{
    return true;
}

int LongSwordMetadata::TypeId() const
{
    return 100;
}

void LongSwordMetadata::fillAttributes(std::vector<CardMetadata::CardAttribute> &attributes)
{
    attributes.push_back(CardAttribute::Sword);
    attributes.push_back(CardAttribute::ShortRange);
    attributes.push_back(CardAttribute::Slashing);
}
