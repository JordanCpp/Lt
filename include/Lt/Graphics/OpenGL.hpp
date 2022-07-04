#ifndef Lt_Graphics_OpenGL_hpp
#define Lt_Graphics_OpenGL_hpp

#include <Lt/Core/Config.hpp>

#if defined(LT_CONFIG_OS_WINDOWS)
#include <Windows.h>
#include <gl/GL.h>
#else
#error Not support: OpenGL
#endif  

#endif    