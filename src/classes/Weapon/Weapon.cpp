//
// Created by Roger Sioufi on 2024-02-18.
//

#include "Weapon.h"

const std::vector<EnhancementType> Weapon::allowedEnhancements = {
        EnhancementType::AttackBonus, EnhancementType::DamageBonus
};

Weapon::Weapon(const std::string& name, const Enchantment& enchantment) : Item(name, enchantment) {
    if (std::find(allowedEnhancements.begin(), allowedEnhancements.end(), enchantment.type) == allowedEnhancements.end()) {
        throw std::runtime_error("Invalid enchantment type for Weapon.");
    }
    CalculateAttributes();
}

std::string Weapon::getType() const {
    return "Weapon";
}

void Weapon::CalculateAttributes() {
    attackBonus = rollDice();
    damageBonus = rollDice();
}
