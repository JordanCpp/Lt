#ifndef Lt_Graphics_Managers_ImageManager_hpp
#define Lt_Graphics_Managers_ImageManager_hpp

#include <Lt/Factories/ImageFactory.hpp>
#include <Lt/Containers/HashMap.hpp>
#include <Lt/Managers/PathManager.hpp>

namespace Lt
{
	namespace Managers
	{
		class Image
		{
		public:
			Image(Lt::Managers::Path* path, Lt::Factories::Image* factory);
			Lt::Graphics::CpuImage* Get(const char* dir, const char* file);
		private:
			Lt::Managers::Path* _Path;
			Lt::Factories::Image* _Factory;
			Lt::Containers::HashMap<Lt::Graphics::CpuImage*, 4096> _Images;
		};
	}
}

#endif    