//
// Created by kir on 26.06.19.
//

#include <algorithm>
#include <string>
#include "CardMetadataProvider.h"
#include "cards/Card.h"
#include "../Logger.h"

using namespace std::string_literals;

CardMetadataProvider &CardMetadataProvider::getInstance()
{
    static CardMetadataProvider instance;
    return instance;
}

const CardMetadata *CardMetadataProvider::getMetadata(int typeId) const
{
    auto it = std::find_if(_metadataVector.begin(), _metadataVector.end(),
            [typeId](const CardMetadata *metadata) -> bool {
                return metadata->TypeId() == typeId;
            });
    return it == _metadataVector.end() ? nullptr : *it;
}

std::vector<const CardMetadata *> CardMetadataProvider::getMetadata(std::function<bool(const CardMetadata *metadata)> comparator) const
{
    std::vector<const CardMetadata *> result;
    for (auto metadata : _metadataVector) {
        if (comparator(metadata)) {
            result.push_back(metadata);
        }
    }
    return result;
}

CardMetadataProvider::CardMetadataProvider()
{

}

void CardMetadataProvider::registerMetadata(CardMetadata *metadata)
{
    if (getMetadata(metadata->TypeId()) != nullptr) {
        throw std::logic_error("Метаданные с типом "s + std::to_string(metadata->TypeId()) + " уже зарегистрирован!");
    }
    _metadataVector.push_back(metadata);
}

// Spells
#include "cards/HealCard.h"
#include "cards/EvilDetection.h"
#include "cards/FindTraps.h"
#include "cards/Divination.h"
#include "cards/EnergyBolt.h"
#include "cards/Amplification.h"
// Weapons
#include "cards/LongSword.h"

void CardMetadataProvider::init()
{
    Logger::getInstace().log("Инициализация метаданных карт");

    registerMetadata(new HealCardMetadata());
    registerMetadata(new EvilDetectionMetadata());
    registerMetadata(new FindTrapsMetadata());
    registerMetadata(new DivinationMetadata());
    registerMetadata(new EnergyBoltMetadata());
    registerMetadata(new AmplificationMetadata());
    registerMetadata(new LongSwordMetadata());

    for (auto metadata : _metadataVector) {
        metadata->load();
    }

    Logger::getInstace().log("Инициализация метаданных карт закончена. Всего метаданных зарегистрировано: "s + std::to_string(_metadataVector.size()));
}
