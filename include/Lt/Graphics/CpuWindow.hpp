#ifndef Lt_Graphics_CpuWindow_hpp
#define Lt_Graphics_CpuWindow_hpp

#include <Lt/Core/Config.hpp>

#if defined(LT_CONFIG_OS_WINDOWS)
#include <Lt/Platforms/Windows/Graphics/CpuWindow.hpp>
namespace Lt
{
	namespace Graphics
	{
		typedef Lt::Graphics::Windows::CpuWindow CpuWindow;
	}
}
#else
#error Not support: Graphics::CpuWindow
#endif

#endif    