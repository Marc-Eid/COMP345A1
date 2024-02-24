cmake_minimum_required(VERSION 3.20)
project(COMP345A1)

set(CMAKE_CXX_STANDARD 20)


add_executable(COMP345A1 src/main.cpp
        src/classes/Character/Character.cpp
        src/classes/Fighter/Fighter.cpp
        src/classes/Item/Item.h
        src/classes/Item/Item.cpp
        src/classes/Helmet/Helmet.cpp
        src/classes/Helmet/Helmet.h
        src/classes/ItemContainer/ItemContainer.cpp
        src/classes/ItemContainer/ItemContainer.h
        src/classes/Armor/Armor.cpp
        src/classes/Armor/Armor.h
        src/classes/Shield/Shield.cpp
        src/classes/Shield/Shield.h
        src/classes/Ring/Ring.cpp
        src/classes/Ring/Ring.h
        src/classes/Belt/Belt.cpp
        src/classes/Belt/Belt.h
        src/classes/Boots/Boots.cpp
        src/classes/Boots/Boots.h
        src/classes/Weapon/Weapon.cpp
        src/classes/Weapon/Weapon.h
        src/classes/Cell/Cell.cpp
        src/classes/Map/Map.cpp
        src/classes/Dice/Dice.cpp
)


# Test suite
enable_testing()
add_executable(UnitTests src/TestRunner.cpp
        src/classes/Character/Character.cpp
        src/classes/Fighter/Fighter.cpp
        src/tests/TestFighter/TestFighter.cpp
        src/classes/Dice/Dice.cpp
        src/classes/Item/Item.h
        src/classes/Item/Item.cpp
        src/classes/Helmet/Helmet.cpp
        src/classes/Helmet/Helmet.h
        src/classes/ItemContainer/ItemContainer.cpp
        src/classes/ItemContainer/ItemContainer.h
        src/classes/Armor/Armor.cpp
        src/classes/Armor/Armor.h
        src/classes/Shield/Shield.cpp
        src/classes/Shield/Shield.h
        src/classes/Ring/Ring.cpp
        src/classes/Ring/Ring.h
        src/classes/Belt/Belt.cpp
        src/classes/Belt/Belt.h
        src/classes/Boots/Boots.cpp
        src/classes/Boots/Boots.h
        src/classes/Weapon/Weapon.cpp
        src/classes/Weapon/Weapon.h
        src/tests/TestDice/TestDice.cpp
        src/tests/TestItems/TestItems.cpp
        src/tests/TestItems/TestItems.h)

if(APPLE)
    # Configuration for Mac users
    # Include directories for CppUnit headers
    target_include_directories(UnitTests PRIVATE "/usr/local/opt/cppunit/include")

    #Specify the output directory for the UnitTests executable
    set_target_properties(UnitTests PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

    # Link against the CppUnit library
    target_link_directories(UnitTests PRIVATE "/usr/local/opt/cppunit/lib")
    target_link_libraries(UnitTests debug cppunit optimized cppunit)
elseif(WIN32)
    # Configuration for Windows users
    # Include directories for CppUnit headers
    target_include_directories(UnitTests PRIVATE "./CppUnit/include")

    # Link directories for CppUnit library
    target_link_directories(UnitTests PRIVATE "./CppUnit/lib")

    # Link against the CppUnit library
    target_link_libraries(UnitTests debug "cppunitd.lib" optimized "cppunit.lib")
endif()