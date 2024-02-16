cmake_minimum_required(VERSION 3.27)
project(COMP345A1)

set(CMAKE_CXX_STANDARD 20)


add_executable(COMP345A1 main.cpp
        Character.h
        Fighter.h
        Character.cpp
        Fighter.cpp
)


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
target_include_directories(UnitTests PRIVATE "C:/CppUnit/include")

# Link directories for CppUnit library
target_link_directories(UnitTests PRIVATE "C:/CppUnit/lib")

# Link against the CppUnit library
target_link_libraries(UnitTests
    debug "cppunitd.lib" 
    optimized "cppunit.lib")