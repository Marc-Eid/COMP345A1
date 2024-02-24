#include <cppunit/extensions/HelperMacros.h>
#include "../../classes/ItemContainer/ItemContainer.h"
#include "../../classes/Item/Item.h"
#include "../../classes/Helmet/Helmet.h"
#include "../../classes/Armor/Armor.h"

class TestItems : public CppUnit::TestFixture {
CPPUNIT_TEST_SUITE(TestItems);
        CPPUNIT_TEST(testAddItem);
        CPPUNIT_TEST(testGetItem);
    CPPUNIT_TEST_SUITE_END();

public:
    void testAddItem();
    void testGetItem();
};
