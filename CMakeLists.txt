cmake_minimum_required(VERSION 3.18)

project(Assumption
        VERSION 0.1.0
        LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(
        FMT
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG 8.1.1
)
FetchContent_MakeAvailable(FMT)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.12.0
)
FetchContent_MakeAvailable(googletest)

add_library(Assumption)
target_sources(Assumption PRIVATE assumption.hpp)
target_include_directories(Assumption PUBLIC .)
target_compile_options(Assumption PRIVATE -Wall -Wextra)
target_link_libraries(Assumption PUBLIC fmt::fmt)

add_executable(example example.cpp)
target_link_libraries(example PRIVATE Assumption)

enable_testing()
add_executable(tests tests.cpp)
target_link_libraries(tests PRIVATE Assumption GTest::gtest_main)
include(GoogleTest)
gtest_add_tests(TARGET tests)
