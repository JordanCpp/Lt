#include <Lt/Core/TestEqual.hpp>
#include <Lt/Managers/PathManager.hpp>
#include <Lt/Core/Chars.hpp>

void TestManagersPathManager()
{
	Lt::Managers::PathManager path("TestFiles/");

	LT_TEST_EQUAL(Lt::Chars::Equal(path.Get("imeges/", "sample.png"), "TestFiles/imeges/sample.png") == true);
}

int main()
{
	TestManagersPathManager();

	return 0;
}