#ifndef Lt_Platforms_Windows_Core_Directory_hpp
#define Lt_Platforms_Windows_Core_Directory_hpp

#include <Windows.h>
#include <Lt/Core/FileInfo.hpp>

namespace Lt
{
	namespace Core
	{
		class Directory
		{
		public:
			bool Open(const char* path);
			void Close();
			bool Next(Lt::Core::FileInfo& fileInfo);
		private:
			HANDLE _File;
			WIN32_FIND_DATA _Data;
		};
	}
}

#endif    