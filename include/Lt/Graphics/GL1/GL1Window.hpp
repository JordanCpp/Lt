#ifndef Lt_Graphics_GL1Window_hpp
#define Lt_Graphics_GL1Window_hpp

#include <Lt/Core/Config.hpp>

#if defined(LT_CONFIG_OS_WINDOWS)
#include <Lt/Platforms/Windows/Graphics/GL1Window.hpp>
namespace Lt
{
	namespace Graphics
	{
		typedef Lt::Graphics::Windows::GL1Window Window;
	}
}
#elif defined(LT_CONFIG_OS_LINUX)
#include <Lt/Platforms/Linux/Graphics/Window.hpp>
namespace Lt
{
	namespace Graphics
	{
		typedef Lt::Graphics::Linux::Window Window;
	}
}
#else
#error Not support: Graphics::Window
#endif

#endif    