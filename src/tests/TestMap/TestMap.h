//
// Created by hp on 24/02/2024.
//

#include "cppunit/extensions/HelperMacros.h"
#include "../../classes/Map/Map.h"

using namespace std;

class TestMap : public CppUnit::TestFixture{
    CPPUNIT_TEST_SUITE(TestMap);
    CPPUNIT_TEST(testMapPlacement);
    CPPUNIT_TEST(testValidity);
    CPPUNIT_TEST_SUITE_END();
public:
    void setUp();
    void tearDown();
protected:
    void testMapPlacement();
    void testValidity();
private:
    Map *map;
};

