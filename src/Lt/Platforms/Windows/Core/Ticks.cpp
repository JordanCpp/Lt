#include <Lt/Core/Ticks.hpp>
#include <Windows.h>

Lt::usize Lt::Core::Ticks()
{
#if defined(LT_CONFIG_CPU_64)
	return GetTickCount64();
#else
	return GetTickCount();
#endif  
}

void Lt::Core::Delay(Lt::usize count)
{
	Sleep(count);
}