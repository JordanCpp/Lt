#ifndef Lt_Core_FileInfo_hpp
#define Lt_Core_FileInfo_hpp

#include <Lt/Containers/StaticString.hpp>

namespace Lt
{
	namespace Core
	{
		class FileInfo
		{
		public:
			const char* Name();
			void Name(const char* source);
		private:
			Lt::Containers::StaticString<4096> _Name;
		};
	}
}

#endif    