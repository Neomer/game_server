//
// Created by kir on 26.06.19.
//

#include "HealCard.h"

HealCard::HealCard() :
        SpellCard()
{

}

HealCardMetadata::HealCardMetadata() :
        SpellCardMetadata()
{

}

int HealCardMetadata::TypeId() const
{
    return 0;
}

std::shared_ptr<Card> HealCardMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new HealCard());
}

std::string_view HealCardMetadata::getCardName() const
{
    return "Исцеление";
}

bool HealCardMetadata::isBeginnerLevel() const
{
    return true;
}

void HealCardMetadata::fillAttributes(std::vector<CardMetadata::CardAttribute> &attributes)
{
    attributes.push_back(CardAttribute::Magic);
    attributes.push_back(CardAttribute::Faith);
    attributes.push_back(CardAttribute::Heal);
}

