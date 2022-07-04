#ifndef Lt_Graphics_Managers_ImageManager_hpp
#define Lt_Graphics_Managers_ImageManager_hpp

#include <Lt/Factories/ImageFactory.hpp>
#include <Lt/Containers/HashMap.hpp>
#include <Lt/Managers/PathManager.hpp>

namespace Lt
{
	namespace Managers
	{
		class ImageManager
		{
		public:
			ImageManager(Lt::Managers::PathManager* path, Lt::Factories::ImageFactory* factory);
			Lt::Graphics::CpuImage* Get(const char* dir, const char* file);
		private:
			Lt::Managers::PathManager* _Path;
			Lt::Factories::ImageFactory* _Factory;
			Lt::Containers::HashMap<Lt::Graphics::CpuImage*> _Images;
		};
	}
}

#endif    