#ifndef Lt_Core_Terminate_hpp
#define Lt_Core_Terminate_hpp

#if defined(LT_CONFIG_OS_WINDOWS)
#include <Lt/Platforms/Windows/Core/Terminate.hpp>
#elif defined(LT_CONFIG_OS_LINUX)
#include <Lt/Platforms/Linux/Core/Terminate.hpp>
#else
#error Not support: Core::Terminate
#endif

#endif    