//
// Created by kir on 26.06.19.
//

#ifndef WEBSOCKETS_CARDMETADATAPROVIDER_H
#define WEBSOCKETS_CARDMETADATAPROVIDER_H

#include <vector>
#include <functional>

class CardMetadata;

class CardMetadataProvider
{
public:
    static CardMetadataProvider &getInstance();

    void init();

    const CardMetadata *getMetadata(int typeId) const;

    std::vector<const CardMetadata *> getMetadata(std::function<bool(const CardMetadata *metadata)> comparator) const;

    void registerMetadata(CardMetadata *metadata);

private:
    CardMetadataProvider();

    ~CardMetadataProvider() = default;

    std::vector<CardMetadata *> _metadataVector;
};


#endif //WEBSOCKETS_CARDMETADATAPROVIDER_H
