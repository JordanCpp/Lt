#ifndef Lt_Core_TestEqual_hpp
#define Lt_Core_TestEqual_hpp

#include <Lt/Core/Types.hpp>

namespace Lt
{
	namespace Core
	{
		void TestEqual(bool condition, const char* description, const char* function, const char * file, Lt::usize line);
	}
}

#define LT_TEST_EQUAL(x) Lt::Core::TestEqual(x, #x, __FUNCTION__, __FILE__, __LINE__)

#endif    