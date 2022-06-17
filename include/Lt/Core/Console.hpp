#ifndef Lt_Core_Console_hpp
#define Lt_Core_Console_hpp

#include <Lt/Core/Config.hpp>

#if defined(LT_CONFIG_OS_WINDOWS)
#include <Lt/Platforms/Windows/Core/Console.hpp>
namespace Lt
{
	namespace Core
	{
		typedef Lt::Core::Windows::Console Console;
	}
}
#elif defined(LT_CONFIG_OS_LINUX)
#include <Lt/Platforms/Linux/Core/Console.hpp>
namespace Lt
{
	namespace Core
	{
		typedef Lt::Core::Linux::Console Console;
	}
}
#else
#error Not support: Core::Console
#endif

#endif    