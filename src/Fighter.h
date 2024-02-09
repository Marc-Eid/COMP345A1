#pragma once
#include "Character.h"

class Fighter : public Character {
public:
    Fighter(const string& name, int level);
    ~Fighter() override = default;
    void calculateAttributes() override;
    void calculateHitPoints() override;
    void calculateArmorClass() override;
    void calculateAttackBonus() override;
    void calculateDamageBonus() override;
    void displayCharacterSheet() const override;
};


