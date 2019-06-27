//
// Created by kir on 26.06.19.
//

#include "Divination.h"

std::shared_ptr<Card> DivinationMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new Divination());
}

std::string_view DivinationMetadata::getCardName() const
{
    return "Гадание";
}

bool DivinationMetadata::isBeginnerLevel() const
{
    return false;
}

int DivinationMetadata::TypeId() const
{
    return 3;
}

DivinationMetadata::DivinationMetadata() :
        SpellCardMetadata()
{

}

void DivinationMetadata::fillAttributes(std::vector<CardMetadata::CardAttribute> &attributes)
{
    attributes.push_back(CardAttribute::Magic);
    attributes.push_back(CardAttribute::Charms);
    attributes.push_back(CardAttribute::Faith);
}

int Divination::getTypeId() const {
    return 3;
}
