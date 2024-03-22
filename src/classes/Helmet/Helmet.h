//
// Created by Roger Sioufi on 2024-02-18.
//

#ifndef COMP345A1_HELMET_H
#define COMP345A1_HELMET_H

#include "../Item/Item.h"
#include <vector>
#include <stdexcept> // For std::runtime_error
#include <algorithm> // For std::find

/**
 * @class Helmet
 * @brief Helmet item class
 *
 * Game Rules: Helmets may enhance Intelligence, Wisdom, or Armor Class.
 * Design: Inherits from Item and specifies Helmet-related functionality
 * Libraries: Inherits <string> from Item.h
 */
class Helmet: public Item {
private:
    /**
     * Static const member that defines the allowedEnhancements of the item
     */
    static const std::vector<EnhancementType> allowedEnhancements;
public:
    /**
     * @brief Construct a new Helmet object.
     *
     * @param name The name of the helmet.
     * @param enchantment The enchantment applied to the helmet.
     */
    Helmet(const string& name, const Enchantment& enchantment);
    /**
     * @brief Get the type of the item.
     *
     * @return std::string Returns the type of the item as a string.
     */
    string getType() const override;

    /**
     * Calculates attribute
     *
     */
    void CalculateAttributes() override;

};


#endif //COMP345A1_HELMET_H
