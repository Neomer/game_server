//
// Created by kir on 26.06.19.
//

#ifndef WEBSOCKETS_DIVINATION_H
#define WEBSOCKETS_DIVINATION_H

#include "SpellCard.h"

class Divination : public SpellCard
{
public:
    int getTypeId() const override;
};

class DivinationMetadata : public SpellCardMetadata
{
public:
    std::shared_ptr<Card> createInstance() const override;

    std::string_view getCardName() const override;

    bool isBeginnerLevel() const override;

    int TypeId() const override;

    DivinationMetadata();

protected:
    void fillAttributes(std::vector<CardMetadata::CardAttribute> &attributes) override;
};


#endif //WEBSOCKETS_DIVINATION_H
