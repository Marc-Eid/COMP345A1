//
// Created by Roger Sioufi on 2024-02-18.
//

#include "Ring.h"

Ring::Ring(const std::string& name, const Enchantment& enchantment) : Item(name, enchantment) {}

string Ring::getType() const {
    return "Ring";
}
