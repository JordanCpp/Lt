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
"src/Lt/Core/Convert.cpp"
"src/Lt/Core/TestEqual.cpp")

if (WIN32)
  target_sources(Lt PRIVATE 
  "src/Lt/Platforms/Windows/Core/MemoryManager.cpp"
  "src/Lt/Platforms/Windows/Core/Console.cpp"
  "src/Lt/Platforms/Windows/Core/Terminate.cpp")
endif()

add_executable(FixedLinear "Tests/Allocators/FixedLinear.cpp")
target_link_libraries(FixedLinear Lt)

add_executable(Convert "Tests/Core/Convert.cpp")
target_link_libraries(Convert Lt)

add_executable(Point2 "Tests/Graphics/Point2.cpp")
target_link_libraries(Point2 Lt)

add_executable(Rect2 "Tests/Graphics/Rect2.cpp")
target_link_libraries(Rect2 Lt)