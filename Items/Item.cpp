//
// Created by Roger Sioufi on 2024-02-18.
//

#include "Item.h"

Item::Item(const string& name, const Enchantment& enchantment): name(name), enchantment(enchantment){
    if (enchantment.bonus < 1 || enchantment.bonus > 5) {
        throw std::runtime_error("Enchantment bonus must be between 1 and 5.");
    }
}

Item::~Item()= default;

Enchantment Item::getEnchantment() const {
    return enchantment;
}

std::string Item::getName() const {
    return name;
}

std::string Item::enchantmentTypeToString(EnhancementType type) {
    switch (type) {
        case EnhancementType::Strength: return "Strength";
        case EnhancementType::Dexterity: return "Dexterity";
        case EnhancementType::Constitution: return "Constitution";
        case EnhancementType::Intelligence: return "Intelligence";
        case EnhancementType::Wisdom: return "Wisdom";
        case EnhancementType::Charisma: return "Charisma";
        case EnhancementType::ArmorClass: return "Armor Class";
        case EnhancementType::AttackBonus: return "Attack Bonus";
        case EnhancementType::DamageBonus: return "Damage Bonus";
        default: return "Unknown";
    }
}


