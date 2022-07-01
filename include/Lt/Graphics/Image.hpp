#ifndef Lt_Graphics_Image_hpp
#define Lt_Graphics_Image_hpp

#include <Lt/Core/Config.hpp>

#if defined(LT_CONFIG_CPU_RENDER)
#include <Lt/Graphics/Cpu/CpuImage.hpp>

namespace Lt
{
	namespace Graphics
	{
		typedef Lt::Graphics::CpuImage Image;
	}
}

#elif defined(LT_CONFIG_GPU_RENDER)
#include <Lt/Graphics/GpuImage.hpp>

namespace Lt
{
	namespace Graphics
	{
		typedef Lt::Graphics::GpuImage Image;
	}
}
#endif

#endif    