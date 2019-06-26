//
// Created by kir on 26.06.19.
//

#ifndef WEBSOCKETS_FINDTRAPS_H
#define WEBSOCKETS_FINDTRAPS_H

#include "SpellCard.h"

class FindTraps : public SpellCard
{
public:
    ~FindTraps() override;

    FindTraps();
};

class FindTrapsMetadata : public SpellCardMetadata
{
public:
    std::shared_ptr<Card> createInstance() const override;

    int TypeId() const override;

    std::string_view getCardName() const override;

    bool isBeginnerLevel() const override;

    FindTrapsMetadata();

protected:
    void fillAttributes(std::vector<CardMetadata::CardAttribute> &attributes) override;
};

#endif //WEBSOCKETS_FINDTRAPS_H
