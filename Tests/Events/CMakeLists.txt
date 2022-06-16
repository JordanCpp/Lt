cmake_minimum_required(VERSION 3.8)

project(TestEvents)

add_executable(Eventer "Eventer.cpp")
target_link_libraries(Eventer LtEvents LtCore)