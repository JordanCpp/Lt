#include <Lt/Core/Console.hpp>
#include <Lt/Core/Directory.hpp>

int main()
{
	Lt::Core::Console console;
	Lt::Core::Directory directory;
	Lt::Core::FileInfo info;

	if (directory.Open("*.*"))
	{
		while (directory.Next(info))
		{
			console.Write(info.Name());
			console.Line();
		}

		console.Show();
	}

	return 0;
}