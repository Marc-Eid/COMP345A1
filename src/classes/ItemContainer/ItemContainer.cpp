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



int ItemContainer::getItemCount() const {
    return items.size(); // Return the number of items in the container
}

bool ItemContainer::removeItem(int index) {
    if(index > items.size() - 1){
        return false;
    }
    for(int i = 0; i< items.size(); i++){
        if(i == index){
            delete items[i];
        }
    }
    return true;

}

bool ItemContainer::itemExist(Item *item) {
    for(auto & i : items){
        if(item == i){
            return true;
        }
    }
    return false;

}

void ItemContainer::printContainer() const {
    cout << "Total No of Equipment " << items.size() << endl;
    for (int i = 0; i < items.size(); ++i) {
        cout << "----------- Slot No " << i << "------------------\n";
        items[i]->printWeapon();
    }
    cout << "------------------------------------\n";
}

vector<Item *> ItemContainer::getItemsByType(const string& type) {
    vector<Item*> list = {};
    for(auto & item : items){
        if(item->getType() == type){
            list.push_back(item);
        }
    }
    return list;
}



