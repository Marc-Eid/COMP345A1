cmake_minimum_required(VERSION 3.20)
project(COMP345A1)

set(CMAKE_CXX_STANDARD 20)


add_executable(COMP345A1 src/main.cpp
        src/classes/Character/Character.cpp
        src/classes/Fighter/Fighter.cpp
#        Items/Item.h Items/Helmet.cpp Items/Helmet.h Containers/ItemContainer.cpp Containers/ItemContainer.h Items/Item.cpp Items/Armor.cpp Items/Armor.h Items/Shield.cpp Items/Shield.h Items/Ring.cpp Items/Ring.h Items/Belt.cpp Items/Belt.h Items/Boots.cpp Items/Boots.h Items/Weapon.cpp Items/Weapon.h
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
        src/tests/TestDice/TestDice.cpp
)


# Include directories for CppUnit headers
target_include_directories(UnitTests PRIVATE "./CppUnit/include")

# Link directories for CppUnit library
target_link_directories(UnitTests PRIVATE "./CppUnit/lib")

# Link against the CppUnit library
target_link_libraries(UnitTests
    debug "cppunitd.lib" 
    optimized "cppunit.lib")


#[[

#Configuration for Oliver Hassan using CppUnit installed by Homebrew on Mac
# Include directories for CppUnit headers
target_include_directories(UnitTests PRIVATE "/usr/local/opt/cppunit/include")

#Specify the output directory for the UnitTests executable
set_target_properties(UnitTests PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Link against the CppUnit library
target_link_directories(UnitTests PRIVATE "/usr/local/opt/cppunit/lib")
target_link_libraries(UnitTests debug cppunit optimized cppunit)

]]
