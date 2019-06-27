//
// Created by kir on 26.06.19.
//

#include "EnergyBolt.h"

std::shared_ptr<Card> EnergyBoltMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new EnergyBolt());
}

std::string_view EnergyBoltMetadata::getCardName() const
{
    return "Энергетический снаряд";
}

bool EnergyBoltMetadata::isBeginnerLevel() const
{
    return true;
}

int EnergyBoltMetadata::TypeId() const
{
    return 4;
}

void EnergyBoltMetadata::fillAttributes(std::vector<CardMetadata::CardAttribute> &attributes)
{
    attributes.push_back(CardAttribute::Magic);
    attributes.push_back(CardAttribute::Charms);
    attributes.push_back(CardAttribute::Attack);
    attributes.push_back(CardAttribute::Energy);
}

int EnergyBolt::getTypeId() const {
    return 4;
}
