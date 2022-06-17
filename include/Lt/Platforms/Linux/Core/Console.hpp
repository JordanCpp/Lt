#ifndef Lt_Platforms_Linux_Core_Console_hpp
#define Lt_Platforms_Linux_Core_Console_hpp

#include <Lt/Core/Types.hpp>
#include <Lt/Core/IntegerToString.hpp>
#include <Lt/Core/BaseConsole.hpp>

namespace Lt
{
	namespace Core
	{
		namespace Linux
		{
			class Console
			{
			public:
				Console();
				~Console();
				void Show();
				void Line();
				void Write(const char* source);
				void Write(const Lt::Containers::String& source);
				void Write(Lt::isize source);
			private:
				Lt::Core::BaseConsole _BaseConsole;
				Lt::Core::IntegerToString _Convert;
			};
		}
	}
}

#endif    