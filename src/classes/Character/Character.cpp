#include "Character.h"
#include <iostream>
#include <random>


Character::Character(const string& name, int level) : name(name), level(level) {
    generateAbilityScores(); // General ability score generation
    hitPoints = 0;
    armorClass = 0;
    attackBonus = 0;
    damageBonus = 0;
}

void Character::generateAbilityScores() {
    abilityScores["Strength"] = rollDice(3, 6);
    abilityScores["Dexterity"] = rollDice(3, 6);
    abilityScores["Constitution"] = rollDice(3, 6);
    abilityScores["Intelligence"] = rollDice(3, 6);
    abilityScores["Wisdom"] = rollDice(3, 6);
    abilityScores["Charisma"] = rollDice(3, 6);

    // Calculate modifiers
    for (const auto& score : abilityScores) {
        modifiers[score.first] = calculateModifier(score.second);
    }
}

int Character::calculateModifier(int abilityScore) {
    return (abilityScore - 10) / 2;
}


int Character::rollDice(int numberOfDice, int diceSides) {
    random_device rd; // Obtain a random number from hardware
    mt19937 generator(rd()); // Seed the generator
    uniform_int_distribution<> distribution(1, diceSides);

    int total = 0;
    for (int i = 0; i < numberOfDice; ++i) {
        total += distribution(generator);
    }
    return total;
}

void Character::equipItem(const string& itemType, const string& itemName) {
    equipment[itemType] = itemName;
    calculateAttributes(); // Recalculate attributes in case the item affects them

    //the Observable object notifies all its registered observers
    Notify();
}

void Character::displayCharacterSheet() const {
    cout << "Character Name: " << name << "\nLevel: " << level << "\n";

    for (const auto& score : abilityScores) {
        cout << score.first << ": " << score.second << " (Modifier: " << modifiers.at(score.first) << ")\n";
    }
    cout << "Hit Points: " << hitPoints << "\nArmor Class: " << armorClass
              << "\nAttack Bonus: " << attackBonus << "\nDamage Bonus: " << damageBonus << "\n";

    cout << "Equipment:";
    if(equipment.empty()){
        cout << " N/A\n";
    }
    for (const auto& item : equipment) {
        cout << "\n" + item.first << ": " << item.second << "\n";
    }
}

int Character::getArmorACValue(const std::string& armorName) {
    // Example armor AC values. In a real game, you'd look these up in a database or data structure.
    map<string, int> armorACValues = {
            {"Leather", 2},
            {"Chain Mail", 5},
            {"Plate", 8}
    };

    // Find the armor in the map and return its AC value, default to 0 if not found
    auto it = armorACValues.find(armorName);
    if (it != armorACValues.end()) {
        return it->second;
    } else {
        return 0; // No AC bonus for unrecognized armor
    }
}