#ifndef Lt_Graphics_GpuRender_hpp
#define Lt_Graphics_GpuRender_hpp

#include <Lt/Core/Config.hpp>

#if defined(LT_CONFIG_OS_WINDOWS)
#include <Lt/Graphics/GL1Render.hpp>
namespace Lt
{
	namespace Graphics
	{
		typedef Lt::Graphics::Windows::GL1Render GpuRender;
	}
}
#else
#error Not support: Graphics::Window
#endif

#endif    