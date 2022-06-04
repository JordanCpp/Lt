#include <Lt/Core/Assert.hpp>
#include <Lt/Core/Console.hpp>
#include <Lt/Core/Terminate.hpp>

void Lt::Core::Assert(bool condition, const char* error, const char* file, Lt::usize line)
{
	if (!condition)
	{
		Lt::Core::Console console;

		console.Write("\n");
		console.Write("Assertion failed: ");
		console.Write(error);
		console.Write(", file ");
		console.Write(file);
		console.Write(", line ");
		console.Write((Lt::isize)line);

		Lt::Core::Terminate();
	}
}