#ifndef Lt_Core_StringToInteger_hpp
#define Lt_Core_StringToInteger_hpp

#include <Lt/Core/Types.hpp>

namespace Lt
{
	namespace Core
	{
		class StringToInteger
		{
		public:
			bool Convert(const char* source);
			Lt::isize Result();
		private:
			Lt::isize _Result;
		};
	}
}

#endif  