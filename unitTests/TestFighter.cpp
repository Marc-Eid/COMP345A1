
#include "TestFighter.h"

void TestFighter::setUp(void) {
    fighterObject = new Fighter("Fighter", 5);
}

void TestFighter::tearDown(void) {
    delete fighterObject;
}

void TestFighter::testCalculateHitpoints() {
    int constitutionModifier = fighterObject->modifiers["Constitution"];

    CPPUNIT_ASSERT(fighterObject->hitPoints == 10 + fighterObject->getLevel() * constitutionModifier );
}

void TestFighter::testCalculateAttackBonus() {

    CPPUNIT_ASSERT(fighterObject->getLevel() + fighterObject->modifiers["Strength"] == fighterObject->attackBonus);
}