#include <Lt/Managers/ImageManager.hpp>

Lt::Managers::Image::Image(Lt::Managers::Path* path, Lt::Factories::Image* factory) :
	_Path(path),
	_Factory(factory)
{
}

Lt::Graphics::CpuImage* Lt::Managers::Image::Get(const char* dir, const char* file)
{
	const char* path = _Path->Get(dir, file);

	Lt::Containers::HashNode<Lt::Graphics::CpuImage*>* p = _Images.Find(path);

	if (p == nullptr)
	{
		p = new Lt::Containers::HashNode<Lt::Graphics::CpuImage*>(path);

		p->Content = _Factory->Get(path);
	}

	return p->Content;
}