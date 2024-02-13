cmake_minimum_required(VERSION 3.27)
project(COMP345A1)

set(CMAKE_CXX_STANDARD 17)

add_executable(COMP345A1 main.cpp
        Character.h
        Fighter.h
        Character.cpp
        Fighter.cpp
)

# Include directories for CppUnit headers
include_directories(C:/cppunit-1.12.1/include)

# Link directories for CppUnit library
link_directories(C:/cppunit-1.12.1/lib)

# Link against the CppUnit library
target_link_libraries(${PROJECT_NAME} "C:/cppunit-1.12.1/lib/cppunit.lib")