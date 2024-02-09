#pragma once

#include <string>
#include <map>

using namespace std;


/**
 * @file Character.h
 * @brief Defines the base class for all characters in a Basic Fantasy RPG setting.
 *
 * This file contains the declaration of the Character class, which serves as the foundation for all character types
 * in the game. It includes basic attributes, equipment handling, and the framework for derived attribute calculations.
 *
 * Game Rules Involved:
 * - Ability scores (Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma) impact various character capabilities.
 * - Hit Points represent the character's health. They are determined by the character's level and Constitution modifier.
 * - Armor Class (AC) determines how difficult it is for enemies to hit the character in combat, affected by the equipped armor.
 * - Attack Bonus and Damage Bonus are derived from ability scores and affect combat effectiveness.
 *
 * Design Brief:
 * The Character class abstracts the common functionalities and attributes of all characters in the game. It uses virtual
 * functions for attribute calculations to allow derived classes to implement specific rules and behaviors. This design
 * promotes code reuse and flexibility, enabling easy extension for different character classes.
 *
 * Libraries Used:
 * - `<string>`: For representing character names and equipment in a human-readable format.
 * - `<map>`: To associate character attributes, modifiers, and equipment slots with their respective values and items.
 *    Chosen for its efficient key-value storage and easy retrieval of character-related data.
 */

class Character {
public:
    Character(const string& name, int level);

    /**
    * @brief Virtual destructor for the Character class.
    *
    * Ensures derived classes are correctly cleaned up. This destructor is virtual to allow for proper cleanup of derived class objects through base class pointers.
    */
    virtual ~Character() = default;

    map<string, int> abilityScores; // Basic Attributes
    map<string, int> modifiers;
    int hitPoints, armorClass, attackBonus, damageBonus; // Derived Attributes
    map<string, string> equipment; // Equipment Slots


    /**
    * @brief Pure virtual method to calculate derived attributes.
    *
    * Implementations should calculate attributes specific to the character type, such as attack bonuses and hit points, based on the character's level and ability scores.
    */
    virtual void calculateAttributes() = 0;


    /**
    * @brief Equips an item to the character.
    *
    * This method assigns an item to the specified equipment slot. If an item is already equipped in the slot,
    * it will be replaced by the new item.
    *
    * @param itemCategory The category of the item (e.g., "weapon", "armor").
    * @param itemName The name of the item to be equipped.
    */
    void equipItem(const std::string& itemCategory, const std::string& itemName);


    /**
    * @brief Pure virtual method to display the character's attribute sheet.
    *
    * Implementations should output all relevant character information, including name, level, ability scores, derived attributes, and equipped items.
    */
    virtual void displayCharacterSheet() const;

protected:
    string name;
    int level;


    /**
    * @brief Generates random ability scores for the character.
    *
    * This method populates the abilityScores map with randomly generated values for each ability score, simulating the rolling of dice.
    */
    void generateAbilityScores();

    /**
    * @brief Calculates the modifier for an ability score.
    *
    * @param abilityScore The ability score from which to calculate the modifier.
    * @return The calculated modifier, based on the ability score.
    */
    static int calculateModifier(int abilityScore);

    /**
    * @brief Pure virtual method to calculate the character's hit points.
    *
    * Implementations should determine the character's total hit points based on level, class, and Constitution modifier.
    */
    virtual void calculateHitPoints() = 0;

    /**
    * @brief Pure virtual method to calculate the character's armor class.
    *
    * Implementations should calculate the armor class based on equipped armor, Dexterity modifier, and any class-specific bonuses.
    */
    virtual void calculateArmorClass() = 0;

    /**
    * @brief Pure virtual method to calculate the character's attack bonus.
    *
    * Implementations should calculate the attack bonus based on the character's level, class, and relevant ability score modifiers.
    */
    virtual void calculateAttackBonus() = 0;

    /**
    * @brief Pure virtual method to calculate the character's damage bonus.
    *
    * Implementations should calculate the damage bonus based on the character's Strength modifier and any class-specific bonuses.
    */
    virtual void calculateDamageBonus() = 0;

    /**
    * @brief Retrieves the armor class value of a specified armor.
    *
    * @param armorName The name of the armor whose AC value is to be retrieved.
    * @return The armor class (AC) value of the specified armor.
    */
    static int getArmorACValue(const string& armorName);

    /**
    * @brief Simulates rolling dice to generate random numbers.
    *
    * @param numberOfDice The number of dice to roll.
    * @param diceSides The number of sides on each die.
    * @return The total result of the dice rolls.
    */
    static int rollDice(int numberOfDice, int diceSides);
};

