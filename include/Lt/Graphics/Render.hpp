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
	}
}
#elif defined(LT_CONFIG_GPU_RENDER)
#include <Lt/Graphics/Gpu/GpuRender.hpp>
namespace Lt
{
	namespace Graphics
	{
		typedef Lt::Graphics::GpuRender Render;
	}
}
#else
#error Not support: Graphics::Render
#endif

#endif    