cmake_minimum_required(VERSION 3.8)

project(TestAllocators)

add_executable(FixedLinear "FixedLinear.cpp")
target_link_libraries(FixedLinear Lt)