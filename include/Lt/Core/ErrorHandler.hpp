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
			bool Error();
			bool Ok();
			const char* Message() const;
			void Message(const char* description);
			void Reset();
		private:
			bool _Error;
			Lt::Containers::StaticString<128> _Message;
		};
	}
}

#endif    