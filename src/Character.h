#pragma once

#include <string>
#include <map>
#include <memory>

using namespace std;


class Character {
public:
    Character(const string& name, int level);
    virtual ~Character() = default;

    // Basic Attributes
    map<string, int> abilityScores;
    map<string, int> modifiers;

    // Derived Attributes
    int hitPoints, armorClass, attackBonus, damageBonus;

    // Equipment Slots
    map<string, string> equipment;

    // Functions
    virtual void calculateAttributes() = 0;
    void equipItem(const std::string& itemCategory, const std::string& itemName);
    virtual void displayCharacterSheet() const;

protected:
    string name;
    int level;

    void generateAbilityScores();
    static int calculateModifier(int abilityScore);
    virtual void calculateHitPoints() = 0;
    virtual void calculateArmorClass() = 0;
    virtual void calculateAttackBonus() = 0;
    virtual void calculateDamageBonus() = 0;

    static int getArmorACValue(const std::string& armorName);

    // Utility Functions
    static int rollDice(int numberOfDice, int diceSides); // Simulate rolling dice
};

