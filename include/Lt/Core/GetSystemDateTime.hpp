   #ifndef Lt_Core_GetSystemDateTime_hpp
#define Lt_Core_GetSystemDateTime_hpp

#if defined(LT_CONFIG_OS_WINDOWS)
#include <Lt/Platforms/Windows/Core/GetSystemDateTime.hpp>
#elif defined(LT_CONFIG_OS_LINUX)
#include <Lt/Platforms/Linux/Core/GetSystemDateTime.hpp>
#else
#error Not support: Core::GetSystemDateTime
#endif

#endif    