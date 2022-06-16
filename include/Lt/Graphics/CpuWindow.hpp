#ifndef Lt_Graphics_CpuWindow_hpp
#define Lt_Graphics_CpuWindow_hpp

#include <Lt/Core/Config.hpp>

#if defined(LT_CONFIG_OS_WINDOWS)
#include <Lt/Platforms/Windows/Graphics/CpuWindow.hpp>
#else
#error Not support: Graphics::CpuWindow
#endif

#endif    