//
// Created by Roger Sioufi on 2024-02-18.
//

#include "Shield.h"


const std::vector<EnhancementType> Shield::allowedEnhancements = {
        EnhancementType::ArmorClass
};

Shield::Shield(const std::string& name, const Enchantment& enchantment) : Item(name, enchantment) {
    if (std::find(allowedEnhancements.begin(), allowedEnhancements.end(), enchantment.type) == allowedEnhancements.end()) {
        throw std::runtime_error("Invalid enchantment type for Shield.");
    }
}

string Shield::getType() const {
    return "Shield";
}

void Shield::CalculateAttributes() {
    armorClass = rollDice();
}
