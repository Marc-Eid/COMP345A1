#include "Belt.h"

Belt::Belt(const std::string& name, const Enchantment& enchantment)
        : Item(name, enchantment) {}

std::string Belt::getType() const {
    return "Belt";
}
