//
// Created by Roger Sioufi on 2024-02-18.
//

#include "Shield.h"

Shield::Shield(const std::string& name, const Enchantment& enchantment) : Item(name, enchantment) {}

string Shield::getType() const {
    return "Shield";
}