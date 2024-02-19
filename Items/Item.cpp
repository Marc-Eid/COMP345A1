//
// Created by Roger Sioufi on 2024-02-18.
//

#include "Item.h"

Item::Item(const string& name, const Enchantment& enchantment): name(name), enchantment(enchantment){}

Item::~Item()= default;

Enchantment Item::getEnchantment() const {
    return enchantment
}


