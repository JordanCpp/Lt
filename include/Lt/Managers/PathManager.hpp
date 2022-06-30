#ifndef Lt_Graphics_Managers_PathManager_hpp
#define Lt_Graphics_Managers_PathManager_hpp

#include <Lt/Containers/StaticString.hpp>

namespace Lt
{
	namespace Managers
	{
		class Path
		{
		public:
			Path(const char* path);
			const char* Get(const char* dir, const char* file);
		private:
			Lt::Containers::StaticString<64> _ShortPath;
			Lt::Containers::StaticString<256> _FullPath;
		};
	}
}

#endif    