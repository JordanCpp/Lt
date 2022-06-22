cmake_minimum_required(VERSION 3.8)

project(LiteToolkit)

include_directories("include")

add_library(LtCore STATIC
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
"src/Lt/Core/FileInfo.cpp"
"src/Lt/Core/ErrorHandler.cpp")

if (WIN32)
  target_sources(LtCore PRIVATE
  "src/Lt/Platforms/Windows/Core/MemoryManager.cpp"
  "src/Lt/Platforms/Windows/Core/Console.cpp"
  "src/Lt/Platforms/Windows/Core/Terminate.cpp"
  "src/Lt/Platforms/Windows/Core/BinaryFile.cpp"
  "src/Lt/Platforms/Windows/Core/Directory.cpp"
  "src/Lt/Platforms/Windows/Core/Ticks.cpp"
  "src/Lt/Platforms/Windows/Graphics/Window.cpp"
  "src/Lt/Platforms/Windows/Graphics/CpuWindow.cpp"
  "src/Lt/Platforms/Windows/Graphics/GL1Window.cpp"
  "src/Lt/Platforms/Windows/Graphics/Monitor.cpp")
elseif(UNIX AND NOT APPLE)
  target_sources(LtCore PRIVATE
  "src/Lt/Platforms/Linux/Core/Console.cpp"
  "src/Lt/Platforms/Linux/Core/Terminate.cpp"
  "src/Lt/Platforms/Linux/Core/BinaryFile.cpp"
  "src/Lt/Platforms/Linux/Core/Directory.cpp"
  "src/Lt/Platforms/Linux/Core/Ticks.cpp"
  "src/Lt/Platforms/Linux/Graphics/Window.cpp"
  "src/Lt/Platforms/Linux/Graphics/CpuWindow.cpp")
endif()

add_library(LtGraphics STATIC
"src/Lt/Graphics/BaseRender.cpp"
"src/Lt/Graphics/BaseWindow.cpp"
"src/Lt/Graphics/Color.cpp"
"src/Lt/Graphics/CpuImage.cpp"
"src/Lt/Graphics/CpuRender.cpp"
"src/Lt/Graphics/FpsLimiter.cpp"
"src/Lt/Graphics/GL1Render.cpp"
"src/Lt/Graphics/FpsCounter.cpp")

if (WIN32)
  target_link_libraries(LtGraphics opengl32)
endif()

add_library(LtAllocators STATIC
"src/Lt/Allocators/FixedLinear.cpp")

add_library(LtEvents STATIC
"src/Lt/Events/Eventer.cpp")

add_subdirectory("Tests/Core")
add_subdirectory("Tests/Containers")
add_subdirectory("Tests/Allocators")
add_subdirectory("Tests/Graphics")
add_subdirectory("Tests/Events")

add_subdirectory("Examples")