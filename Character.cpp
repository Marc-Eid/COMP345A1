//
// Created by marki on 2024-02-05.
//

#include "Character.h"
#include <cmath>
#include <random>


Character::Character(int level, CharacterClass characterClass): level(level), characterClass(characterClass) {
    generateAbilityScores();
    calculateArmorClass();
    calculateAttackBonus();
    calculateAttackBonus();
    calculateDamageBonus();
}


Character::~Character(){}


int Character::calculateModifier(int score) {
    return floor((score - 10)  / 2);
}

void Character::generateAbilityScores() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1,30);

    strength = dis(gen);
    dexterity = dis(gen);
    constitution = dis(gen);
    intelligence = dis(gen);
    wisdom = dis(gen);
    charisma = dis(gen);
}

void Character::calculateArmorClass() {
    int dexModifier = calculateModifier(dexterity);
    armorClass = 10 + dexModifier; // Example: base 10 armor class + dexterity modifier
}

void Character::calculateAttackBonus() {
    int attackModifier = calculateModifier(strength);
    attackBonus = level + attackModifier;
}

void Character::calculateDamageBonus() {
    int damageModifier = calculateModifier(strength);
    damageBonus = damageModifier;
}

//Getters
int Character::getLevel() const { return Character::level; }
CharacterClass Character::getClass() const { return Character::characterClass; }
int Character::getStrength() const { return strength; }
int Character::getDexterity() const { return dexterity; }
int Character::getConstitution() const { return constitution; }
int Character::getIntelligence() const { return intelligence; }
int Character::getWisdom() const { return wisdom; }
int Character::getCharisma() const { return charisma; }
int Character::getHitPoints() const { return hitPoints; }
int Character::getArmorClass() const { return armorClass; }
int Character::getAttackBonus() const { return attackBonus; }
int Character::getDamageBonus() const { return damageBonus; }