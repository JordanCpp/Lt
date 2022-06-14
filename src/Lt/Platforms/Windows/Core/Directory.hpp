#ifndef Lt_Platforms_Windows_Core_Directory_hpp
#define Lt_Platforms_Windows_Core_Directory_hpp

#include <Windows.h>

namespace Lt
{
	namespace Core
	{
		class Directory
		{
		public:
		private:
			HANDLE _File;
			WIN32_FIND_DATA _Data;
		};
	}
}

#endif    