#include <Lt/Platforms/Windows/Core/Terminate.hpp>
#include <Windows.h>

void Lt::Core::Terminate()
{
	ExitProcess(0);
}