#ifndef Lt_Platforms_Windows_Core_Directory_hpp
#define Lt_Platforms_Windows_Core_Directory_hpp

#include <Windows.h>
#include <Lt/Core/FileInfo.hpp>

namespace Lt
{
	namespace Core
	{
		namespace Windows
		{
			class Directory
			{
			public:
				bool Create(const char* path);
				bool Exist(const char* path);
				bool Delete(const char* path);
				bool Open(const char* path);
				void Close();
				bool Next(Lt::Core::FileInfo& fileInfo);
			private:
				HANDLE _File;
				WIN32_FIND_DATA _Data;
			};
		}
	}
}

#endif    