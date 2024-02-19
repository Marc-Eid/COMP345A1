//
// Created by Roger Sioufi on 2024-02-18.
//

#include "Armor.h"

Armor::Armor(const std::string& name, const Enchantment& enchantment)
        : Item(name, enchantment) {}

std::string Armor::getType() const {
    return "Armor";
}
