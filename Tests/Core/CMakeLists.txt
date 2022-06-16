cmake_minimum_required(VERSION 3.8)

project(TestCore)

add_executable(Types "Types.cpp")
target_link_libraries(Types LtCore)

add_executable(Utils "Utils.cpp")
target_link_libraries(Utils LtCore)

add_executable(DateTime "DateTime.cpp")
target_link_libraries(DateTime LtCore)

add_executable(New "New.cpp")
target_link_libraries(New LtCore)

add_executable(Chars "Chars.cpp")
target_link_libraries(Chars LtCore)

add_executable(BinaryFile "BinaryFile.cpp")
target_link_libraries(BinaryFile LtCore)

add_executable(TextFile "TextFile.cpp")
target_link_libraries(TextFile LtCore)

add_executable(Directory "Directory.cpp")
target_link_libraries(Directory LtCore)

add_executable(IntegerToString "IntegerToString.cpp")
target_link_libraries(IntegerToString LtCore)

add_executable(StringToInteger "StringToInteger.cpp")
target_link_libraries(StringToInteger LtCore)

add_executable(BaseConsole "BaseConsole.cpp")
target_link_libraries(BaseConsole LtCore)

add_executable(Memory "Memory.cpp")
target_link_libraries(Memory LtCore)

add_executable(FileInfo "FileInfo.cpp")
target_link_libraries(FileInfo LtCore)

add_executable(Limits "Limits.cpp")
target_link_libraries(Limits LtCore)

add_executable(Ticks "Ticks.cpp")
target_link_libraries(Ticks LtCore)