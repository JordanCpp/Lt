#ifndef Lt_Platforms_Linux_Core_Directory_hpp
#define Lt_Platforms_Linux_Core_Directory_hpp

#include <Lt/Core/FileInfo.hpp>

namespace Lt
{
	namespace Core
	{
		namespace Linux
		{
			class Directory
			{
			public:
				bool Open(const char* path);
				void Close();
				bool Next(Lt::Core::FileInfo& fileInfo);
			private:
			};
		}
	}
}

#endif    