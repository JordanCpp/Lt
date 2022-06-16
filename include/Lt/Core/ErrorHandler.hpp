#ifndef Lt_Core_ErrorHandler_hpp
#define Lt_Core_ErrorHandler_hpp

#include <Lt/Containers/StaticString.hpp>

namespace Lt
{
	namespace Core
	{
		class ErrorHandler
		{
		public:
			ErrorHandler();
			bool IsError();
			const char* Message();
			void Message(const char* description);
			void Reset();
		private:
			bool _IsError;
			Lt::Containers::StaticString<128> _Message;
		};
	}
}

#endif    