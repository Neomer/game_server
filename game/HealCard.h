//
// Created by kir on 26.06.19.
//

#ifndef WEBSOCKETS_HEALCARD_H
#define WEBSOCKETS_HEALCARD_H

#include "SpellCard.h"

class HealCard : public SpellCard
{
public:
    HealCard();

};

class HealCardMetadata : public SpellCardMetadata
{
public:
    HealCardMetadata();

    int TypeId() const override;

    std::shared_ptr<Card> createInstance() const override;

    std::string_view getCardName() const override;

    bool isBeginnerLevel() const override;

protected:
    void fillAttributes(std::vector<CardMetadata::CardAttribute> &attributes) override;
};



#endif //WEBSOCKETS_HEALCARD_H
