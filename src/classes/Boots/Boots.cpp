//
// Created by Roger Sioufi on 2024-02-18.
//

#include "Boots.h"

const std::vector<EnhancementType> Boots::allowedEnhancements = {
        EnhancementType::ArmorClass, EnhancementType::Dexterity
};

Boots::Boots(const std::string& name, const Enchantment& enchantment) : Item(name, enchantment) {
    if (std::find(allowedEnhancements.begin(), allowedEnhancements.end(), enchantment.type) == allowedEnhancements.end()) {
        throw std::runtime_error("Invalid enchantment type for Boots.");
    }
}

string Boots::getType() const {
    return "Boots";
}