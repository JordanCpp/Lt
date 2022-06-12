#ifndef Lt_Platforms_Windows_Core_File_hpp
#define Lt_Platforms_Windows_Core_File_hpp

#include <Lt/Core/Types.hpp>
#include <Windows.h>

namespace Lt
{
	namespace Core
	{
		class File
		{
		public:
			enum Mode
			{
				Reading,
				Writing
			};
			File();
			~File();
			bool Eof();
			bool Open(const char * path, Lt::usize mode);
			void Close();
			Lt::usize Read(Lt::u8* dst, Lt::usize bytes);
		private:
			HANDLE _File;
			Lt::usize _Bytes;
			Lt::usize _Position;
		};
	}
}

#endif    