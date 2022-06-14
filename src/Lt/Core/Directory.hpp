#ifndef Lt_Core_Directory_hpp
#define Lt_Core_Directory_hpp

#include <Lt/Core/Config.hpp>

#if defined(LT_CONFIG_OS_WINDOWS)
#include <Lt/Platforms/Windows/Core/Directory.hpp>
#else
#error Not support: Core::Directory
#endif  

#endif    