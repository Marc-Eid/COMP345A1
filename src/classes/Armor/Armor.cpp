//
// Created by Roger Sioufi on 2024-02-18.
//

#include "Armor.h"


const std::vector<EnhancementType> Armor::allowedEnhancements = {
        EnhancementType::ArmorClass
};

Armor::Armor(const std::string& name, const Enchantment& enchantment) : Item(name, enchantment) {
    if (std::find(allowedEnhancements.begin(), allowedEnhancements.end(), enchantment.type) == allowedEnhancements.end()) {
        throw std::runtime_error("Invalid enchantment type for Armor.");
    }
    if (enchantment.bonus < 1 || enchantment.bonus > 5) {
        throw std::runtime_error("Enchantment bonus must be between 1 and 5.");
    }
    CalculateAttributes();
}

std::string Armor::getType() const {
    return "Armor";
}

void Armor::CalculateAttributes() {
    armorClass = rollDice();
}
