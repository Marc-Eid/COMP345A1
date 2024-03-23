#include "Fighter.h"
#include <iostream>
using namespace std;

Fighter::Fighter(const string& name, int level) : Character(name,level) {
    Fighter::calculateAttributes();
}

void Fighter::calculateAttributes() {
    calculateHitPoints();
    calculateArmorClass();
    calculateDamageBonus();
}

void Fighter::calculateHitPoints() {
    hitPoints = 10 + level * modifiers["Constitution"];
}

void Fighter::calculateArmorClass() {
    int baseArmorClass = armorClass;
    // Check for equipped armor and adjust base AC accordingly
    vector<Item*> item = equipment.getItemsByType("Armor");
    for(auto & i : item){
        baseArmorClass += i->getArmorClass();
    }
    armorClass = baseArmorClass + modifiers["Dexterity"];
}


void Fighter::calculateDamageBonus() {
    damageBonus = modifiers["Strength"];
}

void Fighter::displayCharacterSheet() const {
    Character::displayCharacterSheet(); // Use base class implementation for common details
    // Add any fighter-specific details here
    std::cout << "Class: Fighter\n";
}

bool Fighter::levelUp() {

    cout << "Leveling Up the Fighter \n";
    Dice dice = Dice();
    hitPoints = dice.roll("1d6") + abilityScores["Constitution"];

    for (int & attackBonu : attackBonus)
    {
        attackBonu += 1;
    }
    level++;
    if (level == 6 || level == 11 || level == 16)
    {
        attackBonus.push_back(1);
    }

    return true;

}


