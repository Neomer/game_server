//
// Created by kir on 26.06.19.
//

#ifndef WEBSOCKETS_EVILDETECTION_H
#define WEBSOCKETS_EVILDETECTION_H

#include "SpellCard.h"

class EvilDetection : public SpellCard
{
public:
    EvilDetection();

    ~EvilDetection() override;

};

class EvilDetectionMetadata : public SpellCardMetadata
{
public:
    std::shared_ptr<Card> createInstance() const override;

    int TypeId() const override;

    std::string_view getCardName() const override;

    bool isBeginnerLevel() const override;

    EvilDetectionMetadata();

protected:
    void fillAttributes(std::vector<CardMetadata::CardAttribute> &attributes) override;
};


#endif //WEBSOCKETS_EVILDETECTION_H
