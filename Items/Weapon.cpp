//
// Created by Roger Sioufi on 2024-02-18.
//

#include "Weapon.h"

Weapon::Weapon(const std::string& name, const Enchantment& enchantment) : Item(name, enchantment) {}

std::string Weapon::getType() const {
    return "Weapon";
}