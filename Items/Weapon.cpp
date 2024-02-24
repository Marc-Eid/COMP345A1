//
// Created by Roger Sioufi on 2024-02-18.
//

#include "Weapon.h"
#include <vector>
#include <stdexcept> // For std::runtime_error
#include <algorithm> // For std::find

const std::vector<EnhancementType> Weapon::allowedEnhancements = {
        EnhancementType::AttackBonus, EnhancementType::DamageBonus
};

Weapon::Weapon(const std::string& name, const Enchantment& enchantment) : Item(name, enchantment) {
    if (std::find(allowedEnhancements.begin(), allowedEnhancements.end(), enchantment.type) == allowedEnhancements.end()) {
        throw std::runtime_error("Invalid enchantment type for Weapon.");
    }
}

std::string Weapon::getType() const {
    return "Weapon";
}