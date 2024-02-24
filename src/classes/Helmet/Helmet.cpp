//
// Created by Roger Sioufi on 2024-02-18.
//

#include "Helmet.h"
#include <vector>
#include <stdexcept> // For std::runtime_error
#include <algorithm> // For std::find

const std::vector<EnhancementType> Helmet::allowedEnhancements = {
        EnhancementType::Intelligence, EnhancementType::Wisdom, EnhancementType::ArmorClass
};

Helmet::Helmet(const std::string& name, const Enchantment& enchantment) : Item(name, enchantment) {
    if (std::find(allowedEnhancements.begin(), allowedEnhancements.end(), enchantment.type) == allowedEnhancements.end()) {
        throw std::runtime_error("Invalid enchantment type for Helmet.");
    }
}

string Helmet::getType() const {
    return "Helmet";
}