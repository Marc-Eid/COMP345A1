
#include "CharacterObserver.h"
#include "../Character/Character.h"
#include <iostream>

using namespace std;

CharacterObserver::CharacterObserver(){
};

CharacterObserver::CharacterObserver(Character *character) {
    _subject = character;
    _subject->Attach(this);
}

CharacterObserver::~CharacterObserver() {
    _subject->Detach(this);
}

void CharacterObserver::update() {
    display();
}

void CharacterObserver::display() {
    string name = _subject->getName();
    int level = _subject->getLevel();
    map<string, int> abilityScores = _subject->getAbilityScores();
    map<string, int> modifiers = _subject->getModifiers();
    int hitPoints = _subject ->getHitpoints();
    int armorClass = _subject ->getArmorClass();
    int damageBonus = _subject ->getDamageBonus();
    vector<int> attackBonus = _subject->getAttackBonus();
    map<string, string> equipment = _subject->getEquipment();

    cout << "Character Name: " << name << "\nLevel: " << level << "\n";

    for (const auto& score : abilityScores) {
        cout << score.first << ": " << score.second << " (Modifier: " << modifiers.at(score.first) << ")\n";
    }
    cout << "Hit Points: " << hitPoints << "\nArmor Class: " << armorClass
         << "\nAttack Bonus per round: ";
    for (const int& attackBonu : attackBonus){
        cout << attackBonu + modifiers.at("Strength")<< " ";
    }
         cout << "\nDamage Bonus: " << damageBonus << "\n";

    cout << "Equipment:";
    if(equipment.empty()){
        cout << " N/A\n";
    }
    for (const auto& item : equipment) {
        cout << "\n" + item.first << ": " << item.second << "\n";
    }

    cout << typeid(*_subject).name() << endl;
}
