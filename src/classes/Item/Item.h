//
// Created by Roger Sioufi on 2024-02-18.
//

#ifndef COMP345A1_ITEM_H
#define COMP345A1_ITEM_H

#include <string>
#include <stdexcept>
#include <map>
#include <iostream>
#include "../Dice/Dice.h"

using namespace std;

/**
* @brief Enum class for the different types of enchantments
*
* Game Rules: Enchantments can be of different types and have different bonuses.
*/
enum class EnhancementType {
    Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma, ArmorClass, AttackBonus, DamageBonus
};

/**
* @brief Struct for the enchantment of an item
* 
* Game Rules: Enchantments can be of different types and have different bonuses.
* Design: Used to store the type and bonus of an enchantment.
*/
struct Enchantment {
    int bonus;
    EnhancementType type;
};

/**
 * @brief Base class for all item types in the game
 *
 * Game Rules: Items can influence character stats and have enchantments.
 * Design: Serves as a base for derived item classes like Helmet, Armor, etc.
 * Libraries: <string> for item names
 *
 */
class Item {
protected:
    string name;
    Enchantment enchantment;
    map<string, int> abilityScores; // Basic Attributes
    bool equipped;
    int hitPoints, armorClass, damageBonus, attackBonus; // Derived Attributes

public:
    /**
    * @brief Construct a new Item object.
    *
    * @param name The name of the item.
    * @param enchantment The enchantment applied to the item.
    */
    Item(const string& name, const Enchantment& enchantment);

    /**
    * @brief Destructor for the Item object.
    *
    */
    virtual ~Item();

    /**
    * @brief Get Enchantment type of the item.
    *
    * @return Enchantment Returns the enchantment of the item.
    */
    Enchantment getEnchantment() const;

    /**
    * @brief Get the type of the item.
    *
    * @return string Returns the type of the item.
    */
    virtual string getType() const = 0;

    /**
     * @brief Function to return the name of the item.
     * @return string Returns name of the item.
     */
    string getName() const;

    /**
     * @brief Static Function to convert Enhancement Type type to String
     * @param type EnhancementType
     * @return string Returns Enhancement Type in String
     */
    static std::string enchantmentTypeToString(EnhancementType type);

    /**
     * @brief Will set Attributes for each type of Weapon
     *
     */
    void virtual CalculateAttributes() = 0 ;

    /**
     * Custom Roll for the item ability
     *
     * @return
     */
     int rollDice();

     /**
      * @brief print weapon on the console
      *
      */
      void printWeapon();

      /**
       * @brief gets armor class
       *
       * @return
       */
      int getArmorClass(){return armorClass;};

      /**
       * @brief getter and setters for equipped
       */
       bool getEquipped() {return equipped;};

       /**
        * @brief set Equipped
        */
        void setEquipped(bool value){equipped = value; };

private:
    /**
     * @brief Initializes attributes
     *
     *
     */
    void initializeAttributes();



};


#endif //COMP345A1_ITEM_H
