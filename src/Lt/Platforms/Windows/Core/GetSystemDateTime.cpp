#include <Lt/Platforms/Windows/Core/GetSystemDateTime.hpp>
#include <Windows.h>

void Lt::Core::GetSystemDateTime(Lt::Core::SystemDateTime& dest)
{
	SYSTEMTIME data;

	GetLocalTime(&data);

	dest.Years = (Lt::u16)data.wYear;
	dest.Months = (Lt::u8)data.wMonth;
	dest.Days = (Lt::u8)data.wDay;
	dest.Hours = (Lt::u8)data.wHour;
	dest.Minutes = (Lt::u8)data.wMinute;
	dest.Seconds = (Lt::u8)data.wSecond;
}