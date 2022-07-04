#ifndef Lt_Graphics_Render_hpp
#define Lt_Graphics_Render_hpp

#include <Lt/Core/Config.hpp>

#if defined(LT_CONFIG_CPU_RENDER)
#include <Lt/Graphics/Cpu/CpuRender.hpp>
namespace Lt
{
	namespace Graphics
	{
		typedef Lt::Graphics::CpuRender Render;
		typedef Lt::Graphics::CpuWindow Window;
	}
}
#elif defined(LT_CONFIG_GPU_RENDER)
#include <Lt/Graphics/GL1/GL1Render.hpp>
namespace Lt
{
	namespace Graphics
	{
		typedef Lt::Graphics::GL1Render Render;
		typedef Lt::Graphics::GL1Window Window;
	}
}
#else
#error Not support: Graphics::Render
#endif

#endif    