//
// Created by Roger Sioufi on 2024-02-18.
//

#ifndef COMP345A1_WEAPON_H
#define COMP345A1_WEAPON_H

#include "../Item/Item.h"

/**
 * @class Weapon
 * @brief Represents a weapon item
 *
 * Game Rules: Weapon may enhance Attack Bonus or Damage bonus.
 * Design: Inherits from Item and specifies Weapon-related functionality.
 * Libraries: Inherits <string> from Item.h.
 */
class Weapon: public Item {
private:
    /**
     * Static const member that defines the allowedEnhancements of the item
     */
    static const std::vector<EnhancementType> allowedEnhancements;
public:
    /**
     * @brief Construct a new Weapon object.
     *
     * @param name The name of the weapon.
     * @param enchantment The enchantment applied to the weapon.
     */
    Weapon(const std::string& name, const Enchantment& enchantment);
    
    /**
     * @brief Get the type of the item.
     *
     * @return std::string Returns the type of the item as a string.
     */
    string getType() const override;
};


#endif //COMP345A1_WEAPON_H
