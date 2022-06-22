#ifndef Lt_Graphics_Monitor_hpp
#define Lt_Graphics_Monitor_hpp

#include <Lt/Core/Config.hpp>

#if defined(LT_CONFIG_OS_WINDOWS)
#include <Lt/Platforms/Windows/Graphics/Monitor.hpp>
namespace Lt
{
	namespace Graphics
	{
		typedef Lt::Graphics::Windows::Monitor Monitor;
	}
}
#else
#error Not support: Graphics::Monitor
#endif

#endif    