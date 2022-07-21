#ifndef Arcanum_Engine_hpp
#define Arcanum_Engine_hpp

#include <Lt/Graphics/Render.hpp>
#include <Lt/Graphics/FpsCounter.hpp>
#include <Lt/Core/IntegerToString.hpp>
#include <Lt/Allocators/FixedLinear.hpp>
#include <Lt/Managers/ImageManager.hpp>

namespace Arcanum
{
	class Engine
	{
	public:
		Engine(const Lt::Graphics::Point2u size);
		void Run();
		void CalcFps();
	private:
		Lt::Managers::PathManager _PathManager;
		Lt::Allocators::FixedLinear _GeneralAllocator;
		Lt::Allocators::FixedLinear _ImageLoaderAllocator;
		Lt::Allocators::FixedLinear _ImageCacheAllocator;
		Lt::Loaders::ImageLoader _ImageLoader;
		Lt::Core::ErrorHandler _ErrorHandler;
		Lt::Graphics::Window _Window;
		Lt::Graphics::Render _Render;
		Lt::Graphics::FpsCounter _FpsCounter;
		Lt::Core::IntegerToString _IntegerToString;
		Lt::Factories::ImageFactory _ImageFactory;
		Lt::Managers::ImageManager _ImageCacheManager;
	};
}

#endif    