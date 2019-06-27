//
// Created by kir on 26.06.19.
//

#ifndef WEBSOCKETS_AMPLIFICATION_H
#define WEBSOCKETS_AMPLIFICATION_H

#include "SpellCard.h"

class Amplification : public SpellCard
{
public:
    int getTypeId() const override;
};

class AmplificationMetadata : public SpellCardMetadata
{
public:
    std::shared_ptr<Card> createInstance() const override;

    std::string_view getCardName() const override;

    bool isBeginnerLevel() const override;

    int TypeId() const override;

protected:
    void fillAttributes(std::vector<CardMetadata::CardAttribute> &attributes) override;
};

#endif //WEBSOCKETS_AMPLIFICATION_H
