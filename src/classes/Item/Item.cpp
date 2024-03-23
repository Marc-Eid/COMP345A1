//
// Created by Roger Sioufi on 2024-02-18.
//

#include "Item.h"


Item::Item(const string& name, const Enchantment& enchantment): name(name), enchantment(enchantment){
    if (enchantment.bonus < 1 || enchantment.bonus > 5) {
        throw std::runtime_error("Enchantment bonus must be between 1 and 5.");
    }
    equipped = false;
    initializeAttributes();
}

Item::~Item()= default;

Enchantment Item::getEnchantment() const {
    return enchantment;
}

std::string Item::getName() const {
    return name;
}

int Item::rollDice() {
    Dice dice;
    int em = dice.roll("1d6");
    while (em > 5)
    {
        em = dice.roll("1d6");
    }
    return em;
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

void Item::initializeAttributes() {
    abilityScores["Strength"] = 0;
    abilityScores["Dexterity"] = 0;
    abilityScores["Constitution"] = 0;
    abilityScores["Intelligence"] = 0;
    abilityScores["Wisdom"] = 0;
    abilityScores["Charisma"] = 0;
    armorClass = 0;
    hitPoints = 0;
    attackBonus = 0;
    damageBonus = 0;
}

void Item::printWeapon() {
    cout << "Item :"<< getType() << "\n";
    cout << "Item Name:"<< name << "\n";

    cout << "Enhancement Type : "<<enchantmentTypeToString(enchantment.type) << "   Bonus "<< enchantment.bonus << "\n";
    cout << "Armor Class :" << armorClass << "\n";
    cout << "Hit Points :"<< hitPoints << "\n";
    cout << "damage Bonus  :"<<damageBonus << "\n";
    for (const auto& score : abilityScores) {
        cout << score.first << ": " << score.second << "s\n";
    }

}