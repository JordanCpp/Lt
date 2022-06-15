#ifndef Lt_Core_Assert_hpp
#define Lt_Core_Assert_hpp

#include <Lt/Core/Types.hpp>

namespace Lt
{
	namespace Core
	{
		void Assert(bool condition, const char* error, const char* file, Lt::usize line);
	}
}

#define LT_ASSERT(x) Lt::Core::Assert(x, #x, __FILE__, __LINE__)

#endif    