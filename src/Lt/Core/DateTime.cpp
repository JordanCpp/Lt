#include <Lt/Core/DateTime.hpp>
#include <Lt/Core/Utils.hpp>
#include <Lt/Core/GetSystemDateTime.hpp>

Lt::DateTime::DateTime() :
	_Years(1900),
	_Months(1),
	_Days(1),
	_Hours(0),
	_Minutes(0),
	_Seconds(0)
{
}

Lt::DateTime::DateTime(Lt::u16 year, Lt::u8 month, Lt::u8 day, Lt::u8 hour, Lt::u8 minute, Lt::u8 second) :
	_Years(year),
	_Months(month),
	_Days(day),
	_Hours(hour),
	_Minutes(minute),
	_Seconds(second)
{
}

Lt::u16 Lt::DateTime::Years() const
{
	return _Years;
}

Lt::u8 Lt::DateTime::Months() const
{
	return _Months;
}

Lt::u8 Lt::DateTime::Days() const
{
	return _Days;
}

Lt::u8 Lt::DateTime::Hours() const
{
	return _Hours;
}

Lt::u8 Lt::DateTime::Minutes() const
{
	return _Minutes;
}

Lt::u8 Lt::DateTime::Seconds() const
{
	return _Seconds;
}

void Lt::DateTime::Now()
{
	Lt::Core::SystemDateTime dt;

	Lt::Core::GetSystemDateTime(dt);

	_Years = dt.Years;
	_Months = dt.Months;
	_Days = dt.Days;
	_Hours = dt.Hours;
	_Minutes = dt.Minutes;
	_Seconds = dt.Seconds;
}