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

add_executable(Tests "main.cpp")
target_link_libraries(Tests Lt)