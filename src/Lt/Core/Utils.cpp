#include <Lt/Core/Utils.hpp>

bool Lt::Core::Utils::IsLeapYear(Lt::usize year)
{
	return (year % 4 == 0) || (year % 100 == 0) && (year % 400 == 0);
}