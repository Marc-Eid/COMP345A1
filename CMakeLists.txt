cmake_minimum_required(VERSION 3.20)
project(COMP345A1)

set(CMAKE_CXX_STANDARD 20)


add_executable(COMP345A1 main.cpp
        Character.h
        Fighter.h
        Character.cpp
        Fighter.cpp
#        Items/Item.h Items/Helmet.cpp Items/Helmet.h Containers/ItemContainer.cpp Containers/ItemContainer.h Items/Item.cpp Items/Armor.cpp Items/Armor.h Items/Shield.cpp Items/Shield.h Items/Ring.cpp Items/Ring.h Items/Belt.cpp Items/Belt.h Items/Boots.cpp Items/Boots.h Items/Weapon.cpp Items/Weapon.h
        Cell.cpp
        Map.h
        Map.cpp)


# Test suite
enable_testing()
add_executable(UnitTests unitTests/TestRunner.cpp
        Character.h
        Fighter.h
        Character.cpp
        Fighter.cpp
        unitTests/TestFighter.h
        unitTests/TestFighter.cpp
)

# Include directories for CppUnit headers
target_include_directories(UnitTests PRIVATE "./CppUnit/include")

# Link directories for CppUnit library
target_link_directories(UnitTests PRIVATE "./CppUnit/lib")

# Link against the CppUnit library
target_link_libraries(UnitTests
    debug "cppunitd.lib" 
    optimized "cppunit.lib")