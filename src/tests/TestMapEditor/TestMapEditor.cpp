#include "TestMapEditor.h"

void TestMapEditor::testCreateNewMap() {
    MockInputStream mockInput;
    MockOutputStream mockOutput;

    // Redirect cin and cout to mock streams
    std::streambuf* oldCin = std::cin.rdbuf(mockInput.rdbuf());
    std::streambuf* oldCout = std::cout.rdbuf(mockOutput.rdbuf());

    // Provide fake input
    mockInput.setFakeInput("1\n10\n5\nq\n");

    // Call the function you want to test
    MapEditor mapEditor;
    mapEditor.runEditor(); // Assuming createNewMap is called from runEditor

    // Restore cin and cout
    std::cin.rdbuf(oldCin);
    std::cout.rdbuf(oldCout);

    // Check the output
    CPPUNIT_ASSERT_EQUAL(std::string("\nChoose an option:\n1: Run map editor\n2: Run campaign editor\n3: Quit\nEnter option: What size map would you like to create?\nMap width = Map height = 10x5 map created.\n"), mockOutput.getOutput());
}

void TestMapEditor::testCreateNewCampaign() {
    MockInputStream mockInput;
    MockOutputStream mockOutput;

    // Redirect cin and cout to mock streams
    std::streambuf* oldCin = std::cin.rdbuf(mockInput.rdbuf());
    std::streambuf* oldCout = std::cout.rdbuf(mockOutput.rdbuf());

    // Provide fake input
    mockInput.setFakeInput("2\n10\n5\nq\n");

    // Call the function you want to test
    MapEditor mapEditor;
    mapEditor.runEditor(); // Assuming createNewCampaign is called from runEditor

    // Restore cin and cout
    std::cin.rdbuf(oldCin);
    std::cout.rdbuf(oldCout);

    // Check the output
    CPPUNIT_ASSERT_EQUAL(std::string("\nChoose an option:\n1: Run map editor\n2: Run campaign editor\n3: Quit\nEnter option: Creating a new campaign.\nEnter initial width and height for the first map of your campaign:\nMap width = Map height = New campaign created.\n"), mockOutput.getOutput());
}

void TestMapEditor::testEditMap() {
    // Similar setup as testCreateNewMap, but for editing a map
}

void TestMapEditor::testSaveMapToFile() {
    // Similar setup as testCreateNewMap, but for saving a map to a file
}

void TestMapEditor::testLoadMapFromFile() {
    // Similar setup as testCreateNewMap, but for loading a map from a file
}

// Implement more test cases similarly

CPPUNIT_TEST_SUITE_REGISTRATION(TestMapEditor);
