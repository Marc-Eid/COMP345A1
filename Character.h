//
// Created by marki on 2024-02-04.
//

#pragma once //Instead of ifndef
#include <string>

using namespace std;


//enum for the Character class
enum class CharacterClass{
    Fighter,
    Wizard,
    Rogue
};

enum class StrengthSkills{
    Athletics
};

enum class DexteritySkills{
    Acrobatics,
    SleightOfHand,
    Stealth
};

enum class IntelligenceSkills{
    Arcana,
    History,
    Investigation,
    Nature,
    Religion
};

enum class WisdomSkills{
    AnimalHandling,
    Insight,
    Medicine,
    Perception,
    Survival
};

enum class CharismaSkills{
    Deception,
    Intimidation,
    Performance,
    Persuasion
};


class Weapon;
class Armor;
class Helmet;
class Shield;
class Boots;
class Ring;

class Character{
public:

    //constructor
    Character(int level, CharacterClass characterClass);

    //destructor
    ~Character();

    //Method to generate ability scores randomly
    void generateAbilityScores();

    //getters
    int getLevel() const;
    CharacterClass getClass() const;
    int getStrength() const;
    int getDexterity() const;
    int getConstitution() const;
    int getIntelligence() const;
    int getWisdom() const;
    int getCharisma() const;
    int getHitPoints() const;
    int getArmorClass() const;
    int getAttackBonus() const;
    int getDamageBonus() const;

    void equipArmor(const Armor& armor);
    void equipShield(const Shield& shield);
    void equipWeapon(const Weapon& weapon);
    void equipBoots(const Boots& boots);
    void equipRing(const Ring& ring);
    void equipHelmet(const Helmet& helmet);

    void unequipArmor();
    void unequipShield();
    void unequipWeapon();
    void unequipBoots();
    void unequipRing();
    void unequipHelmet();

private:

    int level{};
    CharacterClass characterClass;

    //ability scores, generated randomly
    int strength, dexterity, constitution, intelligence, wisdom, charisma;

    int hitPoints; //based on constitution modifier and level
    int armorClass; //based on dexterity modifier
    int attackBonus;  //based on level and strength/dexterity modifiers
    int damageBonus; //based on strength modifier

    Armor equippedArmor;
    Shield equippedShield;
    Weapon equippedWeapon;
    Boots equippedBoots;
    Ring equippedRing;
    Helmet equippedHelmet;


    //helper method
    int calculateModifier(int score);

    virtual void calculateHitPoints() = 0; // for each subclass to implement
    void calculateArmorClass();
    void calculateAttackBonus();
    void calculateDamageBonus();
};
