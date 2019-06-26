//
// Created by kir on 26.06.19.
//

#ifndef WEBSOCKETS_LONGSWORD_H
#define WEBSOCKETS_LONGSWORD_H

#include "WeaponCard.h"

class LongSword : public WeaponCard
{

};

class LongSwordMetadata : public WeaponCardMetadata
{
public:
    std::shared_ptr<Card> createInstance() const override;

    std::string_view getCardName() const override;

    bool isBeginnerLevel() const override;

    int TypeId() const override;

protected:
    void fillAttributes(std::vector<CardMetadata::CardAttribute> &attributes) override;
};


#endif //WEBSOCKETS_LONGSWORD_H
