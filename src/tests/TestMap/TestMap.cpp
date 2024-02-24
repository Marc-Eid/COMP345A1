//
// Created by hp on 24/02/2024.
//

#include "TestMap.h"

//Register Test map as test suit
CPPUNIT_TEST_SUITE_REGISTRATION(TestMap);

void TestMap::setUp() {
    // Create 5 x 5 Map
    map = new Map(5,5);
}

void TestMap::tearDown() {
    delete map;
}

void TestMap::testMapPlacement() {
    // Place a Wall
    bool placed = map->Place(3,2,'#');
    CPPUNIT_ASSERT(placed == true);
}

void TestMap::testValidity() {
    // Place walls,end and start on the map
    map->Place(1,2,'#');
    map->Place(2,2,'#');
    map->Place(0,3,'S');
    map->Place(1,3,'E');
    CPPUNIT_ASSERT(map->isValid() == true);
}