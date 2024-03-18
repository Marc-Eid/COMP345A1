#include "Character.h"
#include <iostream>
#include <random>


Character::Character(const string& name, int level) : name(name), level(level) {
    generateAbilityScores(); // General ability score generation
    hitPoints = 0;
    armorClass = 0;
    damageBonus = 0;
    UpdateAttackBonus();
}

void Character::generateAbilityScores() {

    abilityScores["Strength"] = generateScore();
    abilityScores["Dexterity"] = generateScore();
    abilityScores["Constitution"] = generateScore();
    abilityScores["Intelligence"] = generateScore();
    abilityScores["Wisdom"] = generateScore();
    abilityScores["Charisma"] = generateScore();

    // Calculate modifiers
    for (const auto& score : abilityScores) {
        modifiers[score.first] = calculateModifier(score.second);
    }
}

void Character::UpdateAttackBonus() {
    attackBonus.clear();
    if (level >= 16)
    {

        attackBonus.push_back(level);
        attackBonus.push_back(level - 5);
        attackBonus.push_back(level - 10);
        attackBonus.push_back(level - 15);
    }
    else if (level >= 11)
    {

        attackBonus.push_back(level);
        attackBonus.push_back(level - 5);
        attackBonus.push_back(level - 10);
    }
    else if (level >= 6)
    {

        attackBonus.push_back(level);
        attackBonus.push_back(level - 5);
    }
    else
    {

        attackBonus.push_back(level);
    }
}

int Character::generateScore() {

    int rolls[4];
    int smallestIndex = 0;
    int smallestVal = 24;
    int sum = 0;

    for(int i = 0; i < 4; i++)
    {
        rolls[i] = rollDice(1, 6);
        if(rolls[i] < smallestVal)
        {
            smallestIndex = i;
            smallestVal = rolls[i];
        }
    }

    rolls[smallestIndex] = 0;

    for(int roll : rolls)
    {
        sum += roll;
    }

    return sum;
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
              << "\nAttack Bonus Per Round: ";
    for (const int& attackBonu : attackBonus){
        cout << attackBonu + modifiers.at("Strength")<< " ";
    }
    cout << "\nDamage Bonus: " << damageBonus << "\n";

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

void Character::adjustLevel(int level) {
    this->level = level;
    UpdateAttackBonus();
    calculateAttributes();
}

