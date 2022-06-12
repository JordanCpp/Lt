#ifndef Lt_Core_Utils_hpp
#define Lt_Core_Utils_hpp

#include <Lt/Core/Types.hpp>
#include <Lt/Core/DateTime.hpp>

namespace Lt
{
	namespace Core
	{
		namespace Utils
		{
			bool IsLeapYear(Lt::usize year);
			bool DateIsValid(Lt::u16 year, Lt::u8 month, Lt::u8 day);
			bool TimeIsValid(Lt::u8 hour, Lt::u8 minute, Lt::u8 second);
			bool DateTimeIsValid(const Lt::DateTime& dateTime);
		}
	}
}

#endif   