cmake_minimum_required(VERSION 3.10)

project(OTUS)

add_executable(lec_15_05_filesystem lec_15_05_filesystem.cpp)

set_target_properties(
    lec_15_05_filesystem

PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)