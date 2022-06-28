#include <Lt/Core/Console.hpp>
#include <Lt/Core/IntegerToString.hpp>

int main()
{
	Lt::Core::Console console;
	Lt::Core::IntegerToString toString;

	for (size_t i = 0; i < 15; i++)
	{
		if (toString.Convert(i))
		{
			console.Write(toString.Result());
			console.Line();
		}
	}

	console.Show();

	return 0;
}