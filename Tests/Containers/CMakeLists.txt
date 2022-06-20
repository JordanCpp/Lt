cmake_minimum_required(VERSION 3.8)

project(TestContainers)

add_executable(Vector "Vector.cpp")
target_link_libraries(Vector LtCore)

add_executable(String "String.cpp")
target_link_libraries(String LtCore)

add_executable(Array "Array.cpp")
target_link_libraries(Array LtCore)

add_executable(StaticString "StaticString.cpp")
target_link_libraries(StaticString LtCore)

add_executable(StaticVector "StaticVector.cpp")
target_link_libraries(StaticVector LtCore)

add_executable(CircularBuffer "CircularBuffer.cpp")
target_link_libraries(CircularBuffer LtCore)

add_executable(List "List.cpp")
target_link_libraries(List LtCore)

add_executable(HashMap "HashMap.cpp")
target_link_libraries(HashMap LtCore)