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
"src/Lt/Core/Memory.cpp")

if (WIN32)
  target_sources(Lt PRIVATE 
  "src/Lt/Platforms/Windows/Core/MemoryManager.cpp"
  "src/Lt/Platforms/Windows/Core/Console.cpp"
  "src/Lt/Platforms/Windows/Core/Terminate.cpp")
endif()

add_executable(Concat "Tests/Chars/Concat.cpp")
target_link_libraries(Concat Lt)

add_executable(FixedLinear "Tests/Allocators/FixedLinear.cpp")
target_link_libraries(FixedLinear Lt)

add_executable(IntegerToString "Tests/Core/IntegerToString.cpp")
target_link_libraries(IntegerToString Lt)

add_executable(StringToInteger "Tests/Core/StringToInteger.cpp")
target_link_libraries(StringToInteger Lt)

add_executable(BaseConsole "Tests/Core/BaseConsole.cpp")
target_link_libraries(BaseConsole Lt)

add_executable(Point2 "Tests/Graphics/Point2.cpp")
target_link_libraries(Point2 Lt)

add_executable(Rect2 "Tests/Graphics/Rect2.cpp")
target_link_libraries(Rect2 Lt)

add_executable(Vector "Tests/Containers/Vector.cpp")
target_link_libraries(Vector Lt)