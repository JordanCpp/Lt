cmake_minimum_required(VERSION 3.8)

project(TestCore)

add_executable(Types "Types.cpp")
target_link_libraries(Types Lt)

add_executable(Utils "Utils.cpp")
target_link_libraries(Utils Lt)

add_executable(DateTime "DateTime.cpp")
target_link_libraries(DateTime Lt)

add_executable(New "New.cpp")
target_link_libraries(New Lt)

add_executable(Chars "Chars.cpp")
target_link_libraries(Chars Lt)

add_executable(BinaryFile "BinaryFile.cpp")
target_link_libraries(BinaryFile Lt)

add_executable(TextFile "TextFile.cpp")
target_link_libraries(TextFile Lt)

add_executable(Directory "Directory.cpp")
target_link_libraries(Directory Lt)

add_executable(IntegerToString "IntegerToString.cpp")
target_link_libraries(IntegerToString Lt)

add_executable(StringToInteger "StringToInteger.cpp")
target_link_libraries(StringToInteger Lt)

add_executable(BaseConsole "BaseConsole.cpp")
target_link_libraries(BaseConsole Lt)

add_executable(Memory "Memory.cpp")
target_link_libraries(Memory Lt)

add_executable(FileInfo "FileInfo.cpp")
target_link_libraries(FileInfo Lt)