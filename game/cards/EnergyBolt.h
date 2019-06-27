//
// Created by kir on 26.06.19.
//

#ifndef WEBSOCKETS_ENERGYBOLT_H
#define WEBSOCKETS_ENERGYBOLT_H

#include "SpellCard.h"

class EnergyBolt : public SpellCard
{
public:
    int getTypeId() const override;
};

class EnergyBoltMetadata : public SpellCardMetadata
{
public:
    std::shared_ptr<Card> createInstance() const override;

    std::string_view getCardName() const override;

    bool isBeginnerLevel() const override;

    int TypeId() const override;

protected:
    void fillAttributes(std::vector<CardMetadata::CardAttribute> &attributes) override;
};


#endif //WEBSOCKETS_ENERGYBOLT_H
