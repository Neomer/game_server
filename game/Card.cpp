//
// Created by kir on 26.06.19.
//

#include <algorithm>
#include "Card.h"

Card::~Card()
{

}

CardMetadata::CardMetadata()
{

}

const std::vector<CardMetadata::CardAttribute> &CardMetadata::getAttributes() const
{
    return _attributes;
}

void CardMetadata::load()
{
    fillAttributes(_attributes);
}

bool CardMetadata::hasAttribute(CardAttribute attribute) const
{
    auto it = std::find_if(_attributes.begin(), _attributes.end(),
        [attribute](CardAttribute item) {
            return item == attribute;
        });
    return it != _attributes.end();
}

