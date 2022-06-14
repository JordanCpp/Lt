#ifndef Lt_Core_BaseConsole_hpp
#define Lt_Core_BaseConsole_hpp

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
			void Line();
			void Clear();
			const char* Result();
		private:
			char _Buffer[BufferMax];
		};
	}
}

#endif    