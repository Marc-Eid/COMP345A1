//
// Created by Roger Sioufi on 2024-02-18.
//

#include "ItemContainer.h"
#include "../Weapon/Weapon.h"
#include "../Character/Character.h"
#include "../Armor/Armor.h"
#include "../Belt/Belt.h"
#include "../Boots/Boots.h"
#include "../Ring/Ring.h"
#include "../Shield/Shield.h"

ItemContainer::ItemContainer()= default;

ItemContainer::~ItemContainer() {
    clear();
}

void ItemContainer::addItem(Item *item) {
    items.push_back(item);
}

Item* ItemContainer::getItem(int index) const {
    if (index >=0 && index < items.size()){
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
        cout << "------------------ Slot No " << i << " ------------------\n";
        items[i]->printWeapon();
    }
    cout << "---------------------------------------------\n";
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

std::ostream &operator<<(ostream &os, const ItemContainer &ItemContainer) {
    // Print Item to file
    os << ItemContainer.getItemCount() << " ";
    for(int i =0;i<ItemContainer.getItemCount();i++){
        if(ItemContainer.items[i]->getType() == "Weapon"){
            Weapon *weapon = dynamic_cast<Weapon*>(ItemContainer.items[i]);
            os <<ItemContainer.items[i]->getType()<< " " << weapon->getWeaponType() << " " <<  *ItemContainer.items[i];
        }
        else {
            os << ItemContainer.items[i]->getType() << " " <<  *ItemContainer.items[i] ;
        }

    }
    return os;
}

std::istream &operator>>(istream &is, ItemContainer &ItemContainer) {
    int size;
    is >> size;

    for(int i = 0;i <size;i++){
        string type;
        is >> type;
        if(type == "Weapon") {
            int Type;
            is >> Type;
            if(Type == 0) {
                Item *weapon = new Weapon("sample",Weapon::WeaponType::BOW);
                ItemContainer.addItem(weapon);
                is >> *weapon;
            }
            else {
                Item *weapon = new Weapon("sample",Weapon::WeaponType::SWORD);
                ItemContainer.addItem(weapon);
                is >> *weapon;
            }
        }
        else if (type == "Armor") {
            Item *armor = new Armor("sample");
            ItemContainer.addItem(armor);
            is >> *armor;

        }
        else if (type == "Belt") {
            Item *belt = new Belt("sample");
            ItemContainer.addItem(belt);
            is >> *belt;
        }
        else if (type == "Boots") {
            Item *boots = new Boots("sample");

            ItemContainer.addItem(boots);
            is >> *boots;
        }
        else if (type == "Ring") {
            Item* ring = new Ring("sample");
            ItemContainer.addItem(ring);
            is >> *ring;

        }
        else if (type == "Shield"){
            Item* shield = new Shield("sample");
            ItemContainer.addItem(shield);
            is >> *shield;
        }
    }
    return is;
}

int ItemContainer::getItemIndex(const Item *item) {
    for(int i = 0;i<items.size();i++){
        if(items[i] == item){
            return i;
        }
    }
    return -1;
}

Item *ItemContainer::pickupItemFromContainer(int index) {
    if(index< 0 || index > items.size() - 1){
        return nullptr;
    }
    // check for the item in the chest
    Item* item = items[index];
    for(int i = 0; i< items.size(); i++){
        if(i == index){
            // if yes then erase its reference from the chest
            items.erase(items.begin() + index);
        }
    }
    return item;

}



void ItemContainer::itemPickupMenu(Character *character) {
    while(true){
        if(items.empty()){
            cout << "The chest is empty nothing to pickup" << endl;
            return;
        }
        int input;
        printContainer();
        cout << "Input the Index of the Weapon you want to equip: -1 to Quit" << endl;

        cin >> input;

        if(input == -1){
            return;
        }

        Item * item = pickupItemFromContainer(input);

        if(item == nullptr){
            continue;
        }
        cout << "Adding to the inventory" << endl;
        bool equipped = character->equip(item);
        if(equipped){
            cout << "Successfully Added to the inventory";
            continue;
        }
        else{
            cout << "Error While Equipping the item";
        }
    }
}



