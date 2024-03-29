#include "Character.h"
#include <iostream>
#include <random>
#include <algorithm>

#include "../CharacterStrategy/CharacterStrategy.h"


Character::Character(const string& name, int level) : name(name), level(level) {
    generateAbilityScores(); // General ability score generation
    hitPoints = 0;
    armorClass = 0;
    damageBonus = 0;
    wornItem = nullptr;
    UpdateAttackBonus();
}

void Character::generateAbilityScores() {

    abilityScores["Strength"] = generateScore();
    abilityScores["Dexterity"] = generateScore();
    abilityScores["Constitution"] = generateScore();
    abilityScores["Intelligence"] = generateScore();
    abilityScores["Wisdom"] = generateScore();
    abilityScores["Charisma"] = generateScore();

    // Calculate modifiers
    for (const auto& score : abilityScores) {
        modifiers[score.first] = calculateModifier(score.second);
    }
}

void Character::UpdateAttackBonus() {
    attackBonus.clear();
    if (level >= 16)
    {

        attackBonus.push_back(level);
        attackBonus.push_back(level - 5);
        attackBonus.push_back(level - 10);
        attackBonus.push_back(level - 15);
    }
    else if (level >= 11)
    {

        attackBonus.push_back(level);
        attackBonus.push_back(level - 5);
        attackBonus.push_back(level - 10);
    }
    else if (level >= 6)
    {

        attackBonus.push_back(level);
        attackBonus.push_back(level - 5);
    }
    else
    {
        attackBonus.push_back(level);
    }
}

int Character::generateScore() {

    int rolls[4];
    int smallestIndex = 0;
    int smallestVal = 24;
    int sum = 0;

    for(int i = 0; i < 4; i++)
    {
        rolls[i] = rollDice(1, 6);
        if(rolls[i] < smallestVal)
        {
            smallestIndex = i;
            smallestVal = rolls[i];
        }
    }

    rolls[smallestIndex] = 0;

    for(int roll : rolls)
    {
        sum += roll;
    }

    return sum;
}

int Character::calculateModifier(int abilityScore) {
    return (abilityScore - 10) / 2;
}


int Character::rollDice(int numberOfDice, int diceSides) {
    random_device rd; // Obtain a random number from hardware
    mt19937 generator(rd()); // Seed the generator
    uniform_int_distribution<> distribution(1, diceSides);

    int total = 0;
    for (int i = 0; i < numberOfDice; ++i) {
        total += distribution(generator);
    }
    return total;
}



void Character::displayCharacterSheet() const {
    cout << "Character Name: " << name << "\nLevel: " << level << "\n";

    for (const auto& score : abilityScores) {
        cout << score.first << ": " << score.second << " (Modifier: " << modifiers.at(score.first) << ")\n";
    }
    cout << "Hit Points: " << hitPoints << "\nArmor Class: " << armorClass
              << "\nAttack Bonus Per Round: ";
    for (const int& attackBonu : attackBonus){
        cout << attackBonu << " ";
    }
    cout << "\nDamage Bonus: " << damageBonus << "\n";

    // print the worn Item


    if(wornItem != nullptr){
        cout << " ----------------Worn Equipment-----------------" << endl;
        wornItem->printWeapon();
    }

    // print the available equipment
    cout << "Available Equipment: " << endl;
    equipment.printContainer();


}

int Character::getArmorACValue(const std::string& armorName) {
    // Example armor AC values. In a real game, you'd look these up in a database or data structure.
    map<string, int> armorACValues = {
            {"Leather", 2},
            {"Chain Mail", 5},
            {"Plate", 8}
    };

    // Find the armor in the map and return its AC value, default to 0 if not found
    auto it = armorACValues.find(armorName);
    if (it != armorACValues.end()) {
        return it->second;
    } else {
        return 0; // No AC bonus for unrecognized armor
    }
}

void Character::adjustLevel(int level) {
    this->level = level;
    UpdateAttackBonus();
    calculateAttributes();
}

bool Character::equip(Item *item) {
    // Check is equipment is already equipped
    if(item->getEquipped()){
        cout << "This weapon is already equipped\n";
        return false;
    }
    // If item Exist in the container
    if(equipment.itemExist(item)){
       cout << "Item Already Exist in the Container \n";
       return false;

    }
    // Adds Item to the Container
    item->setEquipped(true);
    equipment.addItem(item);
    return true;
}

bool Character::unequip(int index) {
    Item *item  = equipment.getItem(index);
    if(wornItem == item){
        cout << "In order to remove the item from the equipment container please first remove it \n";
        return false;
    }

    return equipment.removeItem(index);
}

bool Character::wearItem(int index) {
    Item *item  = equipment.getItem(index);

    // Logic to change the Ability scores according to the worn item
    if(wornItem != nullptr ){
        cout << "In order to wear the Item please remove the Worn Item \n";
        return false;
    }

    // If the Item does not exist in the equipment container
    if(item == nullptr){
        cout << "Error Occured\n";
        return false;
    }

    // If everything is good then change the ability scores

    switch (item->getEnchantment().type) {
        case EnhancementType::Strength:
            modifiers["Strength"] += item->getEnchantment().bonus;
            break;
        case EnhancementType::Dexterity:
            modifiers["Dexterity"] += item->getEnchantment().bonus;
            break;
        case EnhancementType::Constitution:
            modifiers["Constitution"] += item->getEnchantment().bonus;
            break;
        case EnhancementType::Intelligence:
            modifiers["Intelligence"] += item->getEnchantment().bonus;
            break;
        case EnhancementType::Wisdom:
            modifiers["Wisdom"] += item->getEnchantment().bonus;
            break;
        case EnhancementType::Charisma:
            modifiers["Charisma"] += item->getEnchantment().bonus;
            break;
        case EnhancementType::ArmorClass:
            armorClass += item->getEnchantment().bonus;
            break;
        case EnhancementType::AttackBonus:
            for (int & attackBonu : attackBonus) {
                attackBonu += item->getEnchantment().bonus;
            }
            break;
        case EnhancementType::DamageBonus:
            damageBonus += item->getEnchantment().bonus;
            break;
    }
    wornItem = item;
    return true;
}

bool Character::remove() {
    if(wornItem == nullptr){
        cout << "Please First Wear to remove";
        return false;
    }
    // If all is good then reverse the ability scores

    switch (wornItem->getEnchantment().type) {
        case EnhancementType::Strength:
            modifiers["Strength"] -= wornItem->getEnchantment().bonus;
            break;
        case EnhancementType::Dexterity:
            modifiers["Dexterity"] -= wornItem->getEnchantment().bonus;
            break;
        case EnhancementType::Constitution:
            modifiers["Constitution"] -= wornItem->getEnchantment().bonus;
            break;
        case EnhancementType::Intelligence:
            modifiers["Intelligence"] -= wornItem->getEnchantment().bonus;
            break;
        case EnhancementType::Wisdom:
            modifiers["Wisdom"] -= wornItem->getEnchantment().bonus;
            break;
        case EnhancementType::Charisma:
            modifiers["Charisma"] -= wornItem->getEnchantment().bonus;
            break;
        case EnhancementType::ArmorClass:
            armorClass -= wornItem->getEnchantment().bonus;
            break;
        case EnhancementType::AttackBonus:
            for (int & attackBonu : attackBonus) {
                attackBonu -= wornItem->getEnchantment().bonus;
            }
            break;
        case EnhancementType::DamageBonus:
            damageBonus += wornItem->getEnchantment().bonus;
            break;
    }
    wornItem = nullptr;
    return true;
}

void Character::onAttacked() {
    if(dynamic_cast<FriendlyStrategy*>(strategy)) { // If current strategy is FriendlyStrategy
        setStrategy(new AggressorStrategy()); // Switch to AggressorStrategy
        notify(name + " now seeks revenge for being attacked and is switching to the dark side  (Aggressor Strategy)");
    }
}

// Define the attack method in the Character class
bool Character::attack(Character* target, int attackRoll) {
    int totalAttack = attackRoll + attackBonus[0]; // Assume first attack bonus is used. You might want to choose based on context.

    cout << target->name << " currently has " << target->hitPoints << " hit points.\n";

    notify(name + " rolls the dice to attack: " + std::to_string(attackRoll) + " + " + std::to_string(attackBonus[0]) + " (bonus) => total = " + std::to_string(totalAttack) + "\n");

    if (totalAttack >= target->armorClass) {
        // The attack hits
        notify("The attack Hits!");
        cout << name << " hits " << target->name << " for a total of " << totalAttack << " damage!\n";

        target->hitPoints -= totalAttack; // Apply damage
        cout << target->name << " now has " << target->hitPoints << " hit points.\n";

        target->onAttacked(); // Notify the target that it's being attacked

        // Additional logic could be added here, such as checking if the target is defeated
        return true; // Attack was successful
    } else {
        // The attack misses
        cout << name << " misses " << target->name << ".\n";
        return false; // Attack missed
    }
}

// Method to set the strategy
void Character::setStrategy(CharacterStrategy* newStrategy) {
    strategy = newStrategy;
}

// Delegating move and attack actions to the strategy
void Character::move(Map* map) {
    if (strategy) strategy->move(this, map);
    else std::cout << name << " has no strategy for moving." << std::endl;
}

void Character::attack(Map* map) {
    if (strategy) strategy->attack(this, map);
    else std::cout << name << " has no strategy for attacking." << std::endl;
}

// Optional: a method for actions not defined in all strategies
void Character::freeAction() {
    // Check if the strategy is of type HumanPlayerStrategy and cast it
    HumanPlayerStrategy* humanStrategy = dynamic_cast<HumanPlayerStrategy*>(strategy);
    if (humanStrategy) {
        humanStrategy->freeAction();
    } else {
        std::cout << name << " has no free actions to perform." << std::endl;
    }
}

void Character::attach(IObserver* observer) {
    observers.push_back(observer);
}

void Character::detach(IObserver* observer) {
    observers.remove(observer);
}

void Character::notify(const std::string& message) {
    if (loggingEnabled){
        for(auto observer : observers) {
            observer->update(message);
        }
    }
}




