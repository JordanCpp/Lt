#include <Lt/Managers/ImageManager.hpp>

Lt::Managers::ImageManager::ImageManager(Lt::Managers::PathManager* path, Lt::Factories::ImageFactory* factory) :
	_Path(path),
	_Factory(factory)
{
}

Lt::Graphics::CpuImage* Lt::Managers::ImageManager::Get(const char* dir, const char* file)
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