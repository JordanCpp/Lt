#ifndef Lt_Core_Chars_hpp
#define Lt_Core_Chars_hpp

#include <Lt/Allocators/Allocator.hpp>

namespace Lt
{
	namespace Chars
	{
		Lt::usize Length(const char* source);
		Lt::isize Compare(const char* x, const char* y);
		bool Equal(const char* x, const char* y);
		bool IsSpace(char symbol);
		bool IsDigit(char symbol);
		void Copy(char* dest, const char* src, Lt::usize limit);
		Lt::usize Concat(char* dst, const char* src, Lt::usize maxlen);
	}
}

#endif    