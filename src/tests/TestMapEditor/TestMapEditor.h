//
// Created by Oliver Hassan on 2024-03-12.
//

#ifndef COMP345A1_TESTMAPEDITOR_H
#define COMP345A1_TESTMAPEDITOR_H

#include <cppunit/extensions/HelperMacros.h>
#include "../../classes/MapEditor/MapEditor.h"
#include <iostream>
#include <sstream>

class MockInputStream : public std::istringstream {
public:
    void setFakeInput(const std::string& fakeInput) {
        str(fakeInput);
        clear();
    }
};

class MockOutputStream : public std::ostringstream {
public:
    std::string getOutput() const {
        return str();
    }
};

class TestMapEditor : public CppUnit::TestFixture {
CPPUNIT_TEST_SUITE(TestMapEditor);
        CPPUNIT_TEST(testCreateNewMap);
        CPPUNIT_TEST(testCreateNewCampaign);
        CPPUNIT_TEST(testEditMap);
        CPPUNIT_TEST(testSaveMapToFile);
        CPPUNIT_TEST(testLoadMapFromFile);
    CPPUNIT_TEST_SUITE_END();

public:
    void testCreateNewMap();
    void testCreateNewCampaign();
    void testEditMap();
    void testSaveMapToFile();
    void testLoadMapFromFile();
};


#endif //COMP345A1_TESTMAPEDITOR_H
