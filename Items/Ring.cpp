//
// Created by Roger Sioufi on 2024-02-18.
//

#include "Ring.h"
#include <vector>
#include <stdexcept> // For std::runtime_error
#include <algorithm> // For std::find

const std::vector<EnhancementType> Ring::allowedEnhancements = {
        EnhancementType::ArmorClass, EnhancementType::Strength, EnhancementType::Constitution,
        EnhancementType::Wisdom, EnhancementType::Charisma
};

Ring::Ring(const std::string& name, const Enchantment& enchantment) : Item(name, enchantment) {
    if (std::find(allowedEnhancements.begin(), allowedEnhancements.end(), enchantment.type) == allowedEnhancements.end()) {
        throw std::runtime_error("Invalid enchantment type for Ring.");
    }
}

string Ring::getType() const {
    return "Ring";
}
