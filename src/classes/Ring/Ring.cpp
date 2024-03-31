//
// Created by Roger Sioufi on 2024-02-18.
//

#include "Ring.h"




Ring::Ring(const std::string& name) : Item(name) {

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
