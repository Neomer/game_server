//
// Created by kir on 26.06.19.
//

#include "LightCrossbow.h"

std::shared_ptr<Card> LightCrossbowMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new LightCrossbow());
}

std::string_view LightCrossbowMetadata::getCardName() const
{
    return "Легкий арбалет";
}

bool LightCrossbowMetadata::isBeginnerLevel() const
{
    return true;
}

int LightCrossbowMetadata::TypeId() const
{
    return 102;
}

void LightCrossbowMetadata::fillAttributes(std::vector<CardMetadata::CardAttribute> &attributes)
{
    attributes.push_back(CardAttribute::Bow);
    attributes.push_back(CardAttribute::LongRange);
    attributes.push_back(CardAttribute::Piercing);
}
