//
// Created by Roger Sioufi on 2024-02-18.
//

#ifndef COMP345A1_ITEMCONTAINER_H
#define COMP345A1_ITEMCONTAINER_H

#include <vector>
#include "../Item/Item.h"


/**
 * @class ItemContainer
 * @brief Container class for storing items
 *
 * Game Rules: Can hold any item type (Helmet, Armor, ...) and used for backpacks, chests, etc.
 * Design: Uses polymorphism to manage a collection of Item pointers
 * Libraries: <vector> for dynamic array of items
 */
class ItemContainer {
public:
    vector<Item*> items;
    ItemContainer();
    ~ItemContainer();

    void addItem(Item* item);
    Item* getItem(int index) const;
    void clear();
    void printItems() const;
};


#endif //COMP345A1_ITEMCONTAINER_H
