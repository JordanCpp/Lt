#ifndef Lt_Core_File_hpp
#define Lt_Core_File_hpp

#include <Lt/Core/Config.hpp>

#if defined(LT_CONFIG_OS_WINDOWS)
#include <Lt/Platforms/Windows/Core/File.hpp>
#else
#error Not support: Core::File
#endif

#endif    