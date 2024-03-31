/**
 * @file ItemContainer.h
 * @brief Defines the ItemContainer class for storing and managing items in a game.
 *
 * Created by Roger Sioufi on 2024-02-18.
 */

#ifndef COMP345A1_ITEMCONTAINER_H
#define COMP345A1_ITEMCONTAINER_H

#include "../Item/Item.h"
#include <vector>
#include <iostream>
#include <iomanip>

/**
 * @class ItemContainer
 * @brief A container class for storing items.
 *
 * ItemContainer can hold any item type (e.g., Helmet, Armor) and is used for various in-game
 * storage units like backpacks, chests, etc. It demonstrates polymorphism by managing a collection
 * of Item pointers.
 */
class ItemContainer {
public:
    /**
     * @brief Default constructor for ItemContainer.
     */
    ItemContainer();

    /**
     * @brief Destructor for ItemContainer.
     *
     * Cleans up allocated memory for items stored in the container.
     */
    ~ItemContainer();

    /**
     * @brief Adds an item to the container.
     *
     * @param item Pointer to the Item to add to the container.
     */
    void addItem(Item* item);

    /**
     * @brief Retrieves an item from the container by index.
     *
     * @param index The index of the item to retrieve.
     * @return Pointer to the requested Item, or nullptr if the index is out of bounds.
     */
    Item* getItem(int index) const;

    /**
     * @brief Clears all items from the container.
     *
     * This function removes all items from the container and deallocates the memory used by them.
     */
    void clear();



    /**
     * @brief Gets the number of items in the container.
     *
     * @return The total number of items stored in the container.
     */
    int getItemCount() const;

    /**
     * Remove Item from the Container
     *
     * @param index
     * @return
     */
    bool removeItem(int index);

    /**
     * Check if item exist in the armory
     *
     * @param item
     * @return
     */
    bool itemExist(Item *item);

    /**
     * @brief Print Container
     *
     */
    void printContainer() const;

    /**
     * @brief will get all the items by type
     *
     * @return
     */
    vector<Item*> getItemsByType(const string& type);

private:
    std::vector<Item*> items; ///< Vector storing pointers to items.
};

#endif // COMP345A1_ITEMCONTAINER_H
