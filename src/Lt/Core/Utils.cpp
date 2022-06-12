#include <Lt/Core/Utils.hpp>

static Lt::u8 normalYear[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
static Lt::u8 leapYear[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool Lt::Core::Utils::IsLeapYear(Lt::usize year)
{
	return (year % 4 == 0) || (year % 100 == 0) && (year % 400 == 0);
}

bool Lt::Core::Utils::DateIsValid(Lt::u16 year, Lt::u8 month, Lt::u8 day)
{
	if (month >= 0 && month <= 12)
	{
		Lt::u8* months = nullptr;

		if (Lt::Core::Utils::IsLeapYear(year))
			months = leapYear;
		else
			months = normalYear;

		return day >= 1 && day <= months[month];
	}

	return false;
}

bool Lt::Core::Utils::TimeIsValid(Lt::u8 hour, Lt::u8 minute, Lt::u8 second)
{
	return hour <= 23 && minute <= 59 && second <= 59;
}

bool Lt::Core::Utils::DateTimeIsValid(const Lt::DateTime& dateTime)
{
	return DateIsValid(dateTime.Years(), dateTime.Months(), dateTime.Days()) && TimeIsValid(dateTime.Hours(), dateTime.Minutes(), dateTime.Seconds());
}