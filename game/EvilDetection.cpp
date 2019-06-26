//
// Created by kir on 26.06.19.
//

#include "EvilDetection.h"

EvilDetection::EvilDetection() :
    SpellCard()
{

}

EvilDetection::~EvilDetection()
{

}

std::shared_ptr<Card> EvilDetectionMetadata::createInstance() const
{
    return std::shared_ptr<Card>(new EvilDetection());
}

int EvilDetectionMetadata::TypeId() const
{
    return 1;
}

std::string_view EvilDetectionMetadata::getCardName() const
{
    return "Обнаружение зла";
}

bool EvilDetectionMetadata::isBeginnerLevel() const
{
    return false;
}

EvilDetectionMetadata::EvilDetectionMetadata() :
        SpellCardMetadata()
{

}

void EvilDetectionMetadata::fillAttributes(std::vector<CardMetadata::CardAttribute> &attributes)
{
    attributes.push_back(CardAttribute::Magic);
    attributes.push_back(CardAttribute::Faith);
}
