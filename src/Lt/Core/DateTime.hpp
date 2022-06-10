#ifndef Lt_Core_DateTime_hpp
#define Lt_Core_DateTime_hpp

#include <Lt/Core/Types.hpp>

namespace Lt
{
	class DateTime
	{
	public:
		DateTime();
		DateTime(Lt::u16 year, Lt::u8 month = 1, Lt::u8 day = 1, Lt::u8 hour = 0, Lt::u8 minute = 0, Lt::u8 second = 0);
		Lt::u16 Years();
		Lt::u8 Months();
		Lt::u8 Days();
		Lt::u8 Hours();
		Lt::u8 Minutes();
		Lt::u8 Seconds();
	private:
		Lt::u16 _Years;
		Lt::u8 _Months;
		Lt::u8 _Days;
		Lt::u8 _Hours;
		Lt::u8 _Minutes;
		Lt::u8 _Seconds;
	};
}

#endif    