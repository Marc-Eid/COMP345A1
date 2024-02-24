//
// Created by Roger Sioufi on 2024-02-18.
//

#ifndef COMP345A1_BELT_H
#define COMP345A1_BELT_H

#include "../Item/Item.h"

/**
 * @class Belt
 * @brief Represents a belt item
 *
 * Game Rules: Belt may enhance Constitution and Strength.
 * Design: Inherits from Item and specifies Belt-related functionality.
 * Libraries: Inherits <string> from Item.h.
 */
class Belt : public Item {
private:
    /**
     * Static const member that defines the allowedEnhancements of the item
     */
    static const std::vector<EnhancementType> allowedEnhancements;
public:
    /**
     * @brief Construct a new Belt object.
     *
     * @param name The name of the belt.
     * @param enchantment The enchantment applied to the belt.
     */
    Belt(const std::string& name, const Enchantment& enchantment);
    
    /**
     * @brief Get the type of the item.
     *
     * @return std::string Returns the type of the item as a string.
     */
    string getType() const override;
};

#endif // COMP345A1_BELT_H
