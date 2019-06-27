//
// Created by kir on 26.06.19.
//

#include "Sling.h"

std::shared_ptr<Card> SlingMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new Sling());
}

std::string_view SlingMetadata::getCardName() const
{
    return "Праща";
}

bool SlingMetadata::isBeginnerLevel() const
{
    return true;
}

int SlingMetadata::TypeId() const
{
    return 101;
}

void SlingMetadata::fillAttributes(std::vector<CardMetadata::CardAttribute> &attributes)
{
    attributes.push_back(CardAttribute::Sling);
    attributes.push_back(CardAttribute::LongRange);
    attributes.push_back(CardAttribute::Crushing);
}

int Sling::getTypeId() const {
    return 101;
}
