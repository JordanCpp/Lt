#ifndef Lt_Core_Config_hpp
#define Lt_Core_Config_hpp

#define LT_CONFIG_GPU_RENDER

#if (_WIN64)
#define LT_CONFIG_OS_WINDOWS
#define LT_CONFIG_CPU_64
#elif (_WIN32)
#define LT_CONFIG_OS_WINDOWS
#define LT_CONFIG_CPU_32
#elif (__linux__ && __x86_64__)
#define LT_CONFIG_OS_LINUX
#define LT_CONFIG_CPU_64
#elif (__linux__ && __i386__)
#define LT_CONFIG_OS_LINUX
#define LT_CONFIG_CPU_32
#endif

#endif    