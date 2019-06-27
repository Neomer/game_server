//
// Created by kir on 26.06.19.
//

#ifndef WEBSOCKETS_LIGHTCROSSBOW_H
#define WEBSOCKETS_LIGHTCROSSBOW_H

#include "WeaponCard.h"

class LightCrossbow : public WeaponCard
{
public:
    int getTypeId() const override;
};

class LightCrossbowMetadata : public WeaponCardMetadata
{
public:
    std::shared_ptr<Card> createInstance() const override;

    std::string_view getCardName() const override;

    bool isBeginnerLevel() const override;

    int TypeId() const override;

protected:
    void fillAttributes(std::vector<CardMetadata::CardAttribute> &attributes) override;
};


#endif //WEBSOCKETS_LIGHTCROSSBOW_H
