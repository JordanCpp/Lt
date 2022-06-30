#ifndef Lt_Graphics_Image_hpp
#define Lt_Graphics_Image_hpp

#include <Lt/Graphics/CpuImageFromAllocator.hpp>
#include <Lt/Graphics/CpuImageFromMemory.hpp>
#include <Lt/Graphics/CpuImageFromNew.hpp>

namespace Lt
{
	namespace Graphics
	{
		typedef Lt::Graphics::CpuImageFromAllocator ImageFromAllocator;
		typedef Lt::Graphics::CpuImageFromMemory ImageFromMemory;
		typedef Lt::Graphics::CpuImageFromNew ImageFromNew;
	}
}

#endif    