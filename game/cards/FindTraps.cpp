//
// Created by kir on 26.06.19.
//

#include "FindTraps.h"


FindTraps::FindTraps() :
        SpellCard()
{

}

FindTraps::~FindTraps()
{

}

int FindTraps::getTypeId() const {
    return 2;
}

std::shared_ptr<Card> FindTrapsMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new FindTraps());
}

int FindTrapsMetadata::TypeId() const
{
    return 2;
}

std::string_view FindTrapsMetadata::getCardName() const
{
    return "Поиск ловушек";
}

bool FindTrapsMetadata::isBeginnerLevel() const
{
    return false;
}

FindTrapsMetadata::FindTrapsMetadata() :
        SpellCardMetadata()
{

}

void FindTrapsMetadata::fillAttributes(std::vector<CardMetadata::CardAttribute> &attributes)
{
    attributes.push_back(CardAttribute::Magic);
    attributes.push_back(CardAttribute::Faith);
}

