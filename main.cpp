#include <Lt/Core/Console.hpp>
#include <Lt/Core/Assert.hpp>

int main()
{
	Lt::Core::Console io;

	io.Write("Hello World!");

	Lt_Core_Assert(1 == 7);

	return 0;
}