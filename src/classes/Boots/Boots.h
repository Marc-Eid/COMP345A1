//
// Created by Roger Sioufi on 2024-02-18.
//

#ifndef COMP345A1_BOOTS_H
#define COMP345A1_BOOTS_H

/**
 * @class Boots
 * @brief Represents a boots item
 *
 * Game Rules: Boots may enhance Armor Class or Dexterity.
 * Design: Inherits from Item and specifies Boots-related functionality.
 * Libraries: Inherits <string> from Item.h.
 */
class Boots {
public:
    /**
     * @brief Construct a new Boots object.
     *
     * @param name The name of the boots.
     * @param enchantment The enchantment applied to the boots.
     */
    Boots(const std::string& name, const Enchantment& enchantment);
    
    /**
     * @brief Get the type of the item.
     *
     * @return std::string Returns the type of the item as a string.
     */
    string getType() const override;
};


#endif //COMP345A1_BOOTS_H
