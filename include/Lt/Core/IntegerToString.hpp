#ifndef Lt_Core_IntegerToString_hpp
#define Lt_Core_IntegerToString_hpp

#include <Lt/Core/Types.hpp>

namespace Lt
{
	namespace Core
	{
		class IntegerToString
		{
		public:
			IntegerToString();
			bool Convert(Lt::isize num, Lt::u8 base = 10);
			const char* Result();
		private:
			void Swap(char& t1, char& t2);
			void Reverse(char * str, Lt::usize length);
			char _Buffer[32];
			int _Result;
		};
	}
}

#endif    