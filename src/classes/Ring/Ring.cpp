//
// Created by Roger Sioufi on 2024-02-18.
//

#include "Ring.h"


const std::vector<EnhancementType> Ring::allowedEnhancements = {
        EnhancementType::ArmorClass, EnhancementType::Strength, EnhancementType::Constitution,
        EnhancementType::Wisdom, EnhancementType::Charisma
};

Ring::Ring(const std::string& name, const Enchantment& enchantment) : Item(name, enchantment) {
    if (std::find(allowedEnhancements.begin(), allowedEnhancements.end(), enchantment.type) == allowedEnhancements.end()) {
        throw std::runtime_error("Invalid enchantment type for Ring.");
    }
    CalculateAttributes();
}

string Ring::getType() const {
    return "Ring";
}

void Ring::CalculateAttributes() {
    armorClass = rollDice();
    abilityScores["Strength"]  = rollDice();
    abilityScores["Constitution"] = rollDice();
    abilityScores["Wisdom"] = rollDice();
    abilityScores["Strength"] = rollDice();
}
