//
// Created by kir on 26.06.19.
//

#include "Amplification.h"

std::shared_ptr<Card> AmplificationMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new Amplification());
}

std::string_view AmplificationMetadata::getCardName() const
{
    return "Усиление";
}

void AmplificationMetadata::fillAttributes(std::vector<CardMetadata::CardAttribute> &attributes)
{
    attributes.push_back(CardAttribute::Magic);
    attributes.push_back(CardAttribute::Charms);
    attributes.push_back(CardAttribute::Faith);
}

bool AmplificationMetadata::isBeginnerLevel() const
{
    return true;
}

int AmplificationMetadata::TypeId() const
{
    return 5;
}

int Amplification::getTypeId() const {
    return 5;
}
