cmake_minimum_required(VERSION 3.12)

project(BigInt)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Werror -pedantic -lm)

add_executable(BigInt main.cpp BigIntFunction.cpp)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(runTests gtests.cpp LongInt.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} gtest gtest_main pthread)
