#include <Lt/Factories/ImageFactory.hpp>
#include <Lt/Core/Memory.hpp>

Lt::Factories::ImageFactory::ImageFactory(Lt::Allocators::Allocator* allocator, Lt::Loaders::ImageLoader* loader) :
	_Allocator(allocator),
	_Loader(loader)
{
}

Lt::Graphics::CpuImage* Lt::Factories::ImageFactory::Get(const char* path)
{
	_Loader->Load(path);

	Lt::usize bytes = _Loader->Size().PosX() * _Loader->Size().PosY() * _Loader->BytesPerPixel();

	Lt::u8* pixels = (Lt::u8*)_Allocator->Allocate(bytes);

	Lt::Memory::Copy(pixels, _Loader->Pixels(), bytes);

	Lt::Graphics::CpuImage* result = new Lt::Graphics::CpuImage(_Loader->Size(), pixels, _Loader->BytesPerPixel());

	return result;
}