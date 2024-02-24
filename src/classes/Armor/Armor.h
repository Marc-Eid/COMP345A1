//
// Created by Roger Sioufi on 2024-02-18.
//

#ifndef COMP345A1_ARMOR_H
#define COMP345A1_ARMOR_H

#include "../Item/Item.h"

/**
* @class Armor
* @brief Represents an armor item
*
 * Game Rules: Armor may enhance Armor Class.
 * Design: Inherits from Item and specifies Helmet-related functionality
 * Libraries: Inherits <string> from Item.h
*/
class Armor : public Item {
private:
    /**
     * Static const member that defines the allowedEnhancements of the item
     */
    static const std::vector<EnhancementType> allowedEnhancements;
public:
    /**
     * @brief Construct a new Armor object.
     *
     * @param name The name of the armor.
     * @param enchantment The enchantment applied to the armor.
     */
    Armor(const std::string& name, const Enchantment& enchantment);

    /**
     * @brief Get the type of the item.
     *
     * @return std::string Returns the type of the item as a string.
     */
    string getType() const override;

};

#endif //COMP345A1_ARMOR_H
