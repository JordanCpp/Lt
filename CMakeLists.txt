cmake_minimum_required(VERSION 3.8)

project(LiteToolkit)

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

add_subdirectory("Tests/Core")
add_subdirectory("Tests/Containers")
add_subdirectory("Tests/Allocators")
add_subdirectory("Tests/Graphics")