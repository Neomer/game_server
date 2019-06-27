//
// Created by vinokurov on 27.06.2019.
//

#ifndef WEBSOCKETS_CARDDECKOWNER_H
#define WEBSOCKETS_CARDDECKOWNER_H

#include <stack>
#include "cards/Card.h"

class CardDeckOwner {
public:
    CardDeckOwner();

    virtual ~CardDeckOwner();

    /**
    * Добавляет карту в колоду
    * @param metadata
    */
    void addCardToDeck(const CardMetadata *metadata);

private:
    std::stack<const CardMetadata *> _deck;
};


#endif //WEBSOCKETS_CARDDECKOWNER_H
