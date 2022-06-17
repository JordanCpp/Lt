#ifndef Lt_Core_BaseConsole_hpp
#define Lt_Core_BaseConsole_hpp

#include <Lt/Containers/StaticString.hpp>
#include <Lt/Containers/String.hpp>

namespace Lt
{
	namespace Core
	{
		class BaseConsole
		{
		public:
			enum
			{
				BufferMax = 4096
			};
			BaseConsole();
			void Append(const char * source);
			void Append(const Lt::Containers::String& source);
			void Line();
			void Clear();
			const char* Result();
		private:
			Lt::Containers::StaticString<BufferMax> _Buffer;
		};
	}
}

#endif    