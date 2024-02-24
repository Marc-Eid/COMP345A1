//
// Created by Roger Sioufi on 2024-02-18.
//

#include "Helmet.h"

Helmet::Helmet(const string &name, const Enchantment &enchantment) : Item(name, enchantment) {}

string Helmet::getType() const {
    return "Helmet";
}