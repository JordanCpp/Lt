#ifndef Lt_Graphics_Render_hpp
#define Lt_Graphics_Render_hpp

#include <Lt/Core/Config.hpp>

#if defined(LT_CONFIG_CPU_RENDER)
#include <Lt/Graphics/CpuRender.hpp>
namespace Lt
{
	namespace Graphics
	{
		typedef Lt::Graphics::CpuRender Render;
	}
}
#endif

#endif    