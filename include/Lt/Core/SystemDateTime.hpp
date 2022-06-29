#ifndef Lt_Core_SystemDateTime_hpp
#define Lt_Core_SystemDateTime_hpp

#include <Lt/Core/Types.hpp>

namespace Lt
{
	namespace Core
	{
		struct SystemDateTime
		{
		public:
			Lt::u16 Years;
			Lt::u8 Months;
			Lt::u8 Days;
			Lt::u8 Hours;
			Lt::u8 Minutes;
			Lt::u8 Seconds;
		};
	}
}

#endif    