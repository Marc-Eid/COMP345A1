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