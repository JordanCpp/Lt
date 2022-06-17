#ifndef Lt_Platforms_Windows_Core_BinaryFile_hpp
#define Lt_Platforms_Windows_Core_BinaryFile_hpp

#include <Lt/Core/Types.hpp>
#include <Windows.h>

namespace Lt
{
	namespace Core
	{
		namespace Windows
		{
			class BinaryFile
			{
			public:
				enum Mode
				{
					Reading,
					Writing
				};
				BinaryFile();
				~BinaryFile();
				Lt::usize Position();
				Lt::usize Size();
				bool Eof();
				bool Open(const char* path, Lt::usize mode);
				void Close();
				Lt::usize Read(Lt::u8* dst, Lt::usize bytes);
			private:
				HANDLE _File;
				Lt::usize _Bytes;
				Lt::usize _Position;
			};
		}
	}
}

#endif    