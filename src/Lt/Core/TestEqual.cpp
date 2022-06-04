#include <Lt/Core/TestEqual.hpp>
#include <Lt/Core/Console.hpp>

void Lt::Core::TestEqual(bool condition, const char* description, const char* function, const char* file, Lt::usize line)
{
	if (!condition)
	{
		Lt::Core::Console console;

		console.Write("\n");
		console.Write("Test failed: ");
		console.Write(description);

		console.Write(", function ");
		console.Write(function);

		console.Write(", file ");
		console.Write(file);

		console.Write(", line ");
		console.Write((Lt::isize)line);
	}
}