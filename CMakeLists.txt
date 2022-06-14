cmake_minimum_required(VERSION 3.8)

project(Refactor)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

include_directories("src")

add_library(Lt STATIC
"src/Lt/Allocators/FixedLinear.cpp"
"src/Lt/Core/New.cpp"
"src/Lt/Core/Assert.cpp"
"src/Lt/Core/Chars.cpp"
"src/Lt/Core/IntegerToString.cpp"
"src/Lt/Core/TestEqual.cpp"
"src/Lt/Core/StringToInteger.cpp"
"src/Lt/Core/BaseConsole.cpp"
"src/Lt/Core/Memory.cpp"
"src/Lt/Core/DateTime.cpp"
"src/Lt/Core/Utils.cpp"
"src/Lt/Core/TextFile.cpp"
"src/Lt/Core/FileInfo.cpp")

if (WIN32)
  target_sources(Lt PRIVATE 
  "src/Lt/Platforms/Windows/Core/MemoryManager.cpp"
  "src/Lt/Platforms/Windows/Core/Console.cpp"
  "src/Lt/Platforms/Windows/Core/Terminate.cpp"
  "src/Lt/Platforms/Windows/Core/BinaryFile.cpp"
  "src/Lt/Platforms/Windows/Core/Directory.cpp")
endif()

add_executable(Types "Tests/Core/Types.cpp")
target_link_libraries(Types Lt)

add_executable(Utils "Tests/Core/Utils.cpp")
target_link_libraries(Utils Lt)

add_executable(DateTime "Tests/Core/DateTime.cpp")
target_link_libraries(DateTime Lt)

add_executable(New "Tests/Core/New.cpp")
target_link_libraries(New Lt)

add_executable(Chars "Tests/Core/Chars.cpp")
target_link_libraries(Chars Lt)

add_executable(BinaryFile "Tests/Core/BinaryFile.cpp")
target_link_libraries(BinaryFile Lt)

add_executable(TextFile "Tests/Core/TextFile.cpp")
target_link_libraries(TextFile Lt)

add_executable(Directory "Tests/Core/Directory.cpp")
target_link_libraries(Directory Lt)

add_executable(FixedLinear "Tests/Allocators/FixedLinear.cpp")
target_link_libraries(FixedLinear Lt)

add_executable(IntegerToString "Tests/Core/IntegerToString.cpp")
target_link_libraries(IntegerToString Lt)

add_executable(StringToInteger "Tests/Core/StringToInteger.cpp")
target_link_libraries(StringToInteger Lt)

add_executable(BaseConsole "Tests/Core/BaseConsole.cpp")
target_link_libraries(BaseConsole Lt)

add_executable(Memory "Tests/Core/Memory.cpp")
target_link_libraries(Memory Lt)

add_executable(Point2 "Tests/Graphics/Point2.cpp")
target_link_libraries(Point2 Lt)

add_executable(Rect2 "Tests/Graphics/Rect2.cpp")
target_link_libraries(Rect2 Lt)

add_executable(Vector "Tests/Containers/Vector.cpp")
target_link_libraries(Vector Lt)

add_executable(String "Tests/Containers/String.cpp")
target_link_libraries(String Lt)