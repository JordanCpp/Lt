cmake_minimum_required(VERSION 3.8)

project(LiteToolkit)

if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

include_directories("include")

add_library(LtCore STATIC
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
  "src/Lt/Platforms/Windows/Core/GetSystemDateTime.cpp"
  "src/Lt/Platforms/Windows/Graphics/Window.cpp"
  "src/Lt/Platforms/Windows/Graphics/CpuWindow.cpp"
  "src/Lt/Platforms/Windows/Graphics/GL1Window.cpp"
  "src/Lt/Platforms/Windows/Graphics/Monitor.cpp"
  "src/Lt/Platforms/Windows/Input/Mouse.cpp")
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
"src/Lt/Graphics/Base/BaseRender.cpp"
"src/Lt/Graphics/Base/BaseWindow.cpp"
"src/Lt/Graphics/Color.cpp"
"src/Lt/Graphics/Cpu/CpuRender.cpp"
"src/Lt/Graphics/FpsLimiter.cpp"
"src/Lt/Graphics/GL1/GL1Render.cpp"
"src/Lt/Graphics/GL1/GL1Image.cpp"
"src/Lt/Graphics/FpsCounter.cpp"
"src/Lt/Graphics/Screenshoter.cpp"
"src/Lt/Graphics/Cpu/CpuImage.cpp"
"src/Lt/Managers/ImageManager.cpp"
"src/Lt/Loaders/ImageLoader.cpp"
"src/Lt/Managers/PathManager.cpp"
"src/Lt/Factories/ImageFactory.cpp"
"src/Lt/Graphics/PixelCalculator.cpp"
"src/Lt/Graphics/PixelConverter.cpp"
"src/Lt/Graphics/Isometric.cpp")

if (WIN32)
  target_link_libraries(LtGraphics opengl32)
endif()

add_library(LtAllocators STATIC
"src/Lt/Allocators/FixedLinear.cpp")

add_library(LtEvents STATIC
"src/Lt/Events/Eventer.cpp")

add_library(LtWidgets STATIC
"src/Lt/Widgets/Widget.cpp"
"src/Lt/Widgets/Factory.cpp"
"src/Lt/Widgets/Button.cpp"
"src/Lt/Widgets/Application.cpp"
"src/Lt/Widgets/Container.cpp"
"src/Lt/View/Rect.cpp"
"src/Lt/View/Line.cpp"
"src/Lt/View/Button.cpp")

add_subdirectory("Tests/Core")
add_subdirectory("Tests/Containers")
add_subdirectory("Tests/Allocators")
add_subdirectory("Tests/Graphics")
add_subdirectory("Tests/Events")
add_subdirectory("Tests/Widgets")
add_subdirectory("Tests/Loaders")
add_subdirectory("Tests/Input")
add_subdirectory("Tests/Managers")
add_subdirectory("Tests/Factories")

add_subdirectory("Examples")