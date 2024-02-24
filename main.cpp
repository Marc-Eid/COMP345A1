#include <iostream>
#include "Fighter.h"
#include "Containers/ItemContainer.h"
#include "Items/Helmet.h"
#include "Items/Armor.h"
#include "Items/Shield.h"
#include "Items/Boots.h"
#include "Items/Ring.h"
void displayFighter();
void displayItemContainer();

int main() {
    displayFighter();
    displayItemContainer();

    return 0;
}

void displayFighter(){
    Fighter f1("test1", 5);
    f1.displayCharacterSheet();

    cout << "\nShowing that the initialization of the two fighter is generated randomly. \n\n";

    Fighter f2("test2", 5);
    f2.displayCharacterSheet();

    // Demonstrate utility function usage
    int diceRoll = Character::rollDice(1, 20); // Simulating a d20 roll
    std::cout << "\nSimulating a d20 roll: " << diceRoll << std::endl;
}

void displayItemContainer(){
    ItemContainer container;

    // Create items and add them to the container
    Item* helmet(new Helmet("Knight's Helmet", Enchantment{5, EnhancementType::ArmorClass}));
    Item* armor(new Armor("Warrior's Armor", Enchantment{2, EnhancementType::ArmorClass}));
    Item* shield(new Shield("Defender's Shield", Enchantment{3, EnhancementType::ArmorClass}));
    Item* ring(new Ring("Ring of Strength", Enchantment{1, EnhancementType::Strength}));
    Item* boots = new Boots("Swiftstride Boots", Enchantment{4, EnhancementType::Dexterity});

    container.addItem(helmet);
    container.addItem(armor);
    container.addItem(shield);
    container.addItem(ring);
    container.addItem(boots);

    cout << endl;
    cout << "Printing elements in the Item Container: " << endl;
    container.printItems();

}
