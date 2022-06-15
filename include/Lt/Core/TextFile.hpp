#ifndef Lt_Core_TextFile_hpp
#define Lt_Core_TextFile_hpp

#include <Lt/Core/BinaryFile.hpp>

namespace Lt
{
	namespace Core
	{
		class TextFile
		{
		public:
			~TextFile();
			bool Open(const char * path);
			void Close();
			char Read();
			bool Eof();
		private:
			Lt::Core::BinaryFile _File;
		};
	}
}

#endif    