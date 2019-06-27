//
// Created by vinokurov on 27.06.2019.
//

#include "CardDeckOwner.h"

CardDeckOwner::CardDeckOwner() {

}

CardDeckOwner::~CardDeckOwner() {

}

void CardDeckOwner::addCardToDeck(const CardMetadata *metadata) {
    _deck.push(metadata);
}
