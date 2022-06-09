#ifndef Lt_Platforms_Windows_Core_Console_hpp
#define Lt_Platforms_Windows_Core_Console_hpp

#include <Lt/Core/Types.hpp>
#include <Lt/Core/IntegerToString.hpp>
#include <Windows.h>

namespace Lt
{
	namespace Core
	{
		class Console
		{
		public:
			Console();
			~Console();
			void Write(const char* source);
			void Write(Lt::isize source);
		private:
			Lt::Core::IntegerToString _Convert;
			HANDLE _Input;
			HANDLE _Output;
		};
	}
}

#endif    