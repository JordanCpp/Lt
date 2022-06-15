#ifndef Lt_Core_Config_hpp
#define Lt_Core_Config_hpp

#if (_WIN64)
#define LT_CONFIG_OS_WINDOWS
#define LT_CONFIG_CPU_64
#elif (_WIN32)
#define LT_CONFIG_OS_WINDOWS
#define LT_CONFIG_CPU_32
#endif

#endif    