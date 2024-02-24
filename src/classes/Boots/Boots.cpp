//
// Created by Roger Sioufi on 2024-02-18.
//

#include "Boots.h"

Boots::Boots(const std::string& name, const Enchantment& enchantment) : Item(name, enchantment) {}

string Boots::getType() const {
    return "Boots";
}