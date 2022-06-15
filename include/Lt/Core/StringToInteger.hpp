#ifndef Lt_Core_StringToInteger_hpp
#define Lt_Core_StringToInteger_hpp

#include <Lt/Core/Types.hpp>
#include <Lt/Containers/String.hpp>

namespace Lt
{
	namespace Core
	{
		class StringToInteger
		{
		public:
			bool Convert(const char* source);
			bool Convert(const Lt::Containers::String& source);
			Lt::isize Result();
		private:
			Lt::isize _Result;
		};
	}
}

#endif  