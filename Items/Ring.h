//
// Created by Roger Sioufi on 2024-02-18.
//

#ifndef COMP345A1_RING_H
#define COMP345A1_RING_H

/**
 * @class Ring
 * @brief Represents a ring item
 *
 * Game Rules: Ring may enhance Armor Class, Constitution, Strength, Wisdom, or Charisma.
 * Design: Inherits from Item and specifies Ring-related functionality.
 * Libraries: Inherits <string> from Item.h.
 */
class Ring {
public:
    /**
     * @brief Construct a new Ring object.
     *
     * @param name The name of the ring.
     * @param enchantment The enchantment applied to the ring.
     */
    Ring(const std::string& name, const Enchantment& enchantment);
    
    /**
     * @brief Get the type of the item.
     *
     * @return std::string Returns the type of the item as a string.
     */
    string getType() const override;
};


#endif //COMP345A1_RING_H
