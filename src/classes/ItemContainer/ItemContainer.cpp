//
// Created by Roger Sioufi on 2024-02-18.
//

#include "ItemContainer.h"

ItemContainer::ItemContainer()= default;

ItemContainer::~ItemContainer() {
    clear();
}

void ItemContainer::addItem(Item *item) {
    items.push_back(item);
}

Item* ItemContainer::getItem(int index) const {
    if (index < items.size()){
        return items[index];
    }
    return nullptr;
}

void ItemContainer::clear() {
    for (Item* item: items){
        delete item;
    }
    items.clear();
}

void ItemContainer::printItems() const {
    std::cout << std::left; // Align text to the left
    std::cout << std::setw(28) << "Name"
              << std::setw(10) << "Type"
              << std::setw(15) << "Enchantment"
              << std::setw(6) << "Bonus" << std::endl;
    std::cout << "-------------------------------------------------------------" << std::endl;
    for (const auto& item : items) {
        Enchantment enchantment = item->getEnchantment();
        std::string enchantmentType;
        enchantmentType = Item::enchantmentTypeToString(enchantment.type);

        std::cout << std::setw(20)<< item->getName() << "\t\t"
                  << std::setw(10) << item->getType() << "\t"
                  << std::setw(15) << enchantmentType << "\t\t"
                  << std::setw(6) << enchantment.bonus << "\n";
    }
}

int ItemContainer::getItemCount() const {
    return items.size(); // Return the number of items in the container
}