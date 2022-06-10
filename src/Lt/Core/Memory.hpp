#ifndef Lt_Core_Memory_hpp
#define Lt_Core_Memory_hpp

#include <Lt/Core/Types.hpp>

namespace Lt
{
	namespace Memory
	{
		void* Copy(void* dst, const void* src, Lt::usize n);
		void* Fill(void* dst, Lt::isize value, Lt::usize bytes);
		void Zero(void* dst, Lt::usize bytes);
	}
}
#endif    