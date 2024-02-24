//
// Created by Roger Sioufi on 2024-02-24.
//

#include "TestItems.h"

void TestItems::testAddItem() {
    ItemContainer container;
    Item* helmet = new Helmet("Test Helmet", Enchantment{1, EnhancementType::ArmorClass});
    container.addItem(helmet);

    // Assuming ItemContainer has a method to get the count of items
    CPPUNIT_ASSERT(container.getItemCount() == 1);

    Item* armor = new Armor("Test Armor", Enchantment{2, EnhancementType::ArmorClass});
    container.addItem(armor);
    CPPUNIT_ASSERT(container.getItemCount() == 2);

}

void TestItems::testGetItem() {
    ItemContainer container;
    Item* helmet = new Helmet("Test Helmet", Enchantment{1, EnhancementType::ArmorClass});
    container.addItem(helmet);

    // Assuming ItemContainer's getItem returns a pointer to the item
    Item* retrievedItem = container.getItem(0);
    CPPUNIT_ASSERT(retrievedItem == helmet); // Check if the returned item is the same as added

}
