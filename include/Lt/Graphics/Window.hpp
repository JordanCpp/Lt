#ifndef Lt_Graphics_Window_hpp
#define Lt_Graphics_Window_hpp

#include <Lt/Core/Config.hpp>

#if defined(LT_CONFIG_OS_WINDOWS)
#include <Lt/Platforms/Windows/Graphics/Window.hpp>
#else
#error Not support: Graphics::Window
#endif

#endif    