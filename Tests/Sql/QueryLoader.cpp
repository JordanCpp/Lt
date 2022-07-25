#include <Lt/Core/TestEqual.hpp>
#include <Lt/Sql/QueryLoader.hpp>

void TestQueryLoaderInit()
{
	Lt::Sql::QueryLoader queryLoader;

	LT_TEST_EQUAL(queryLoader.Buffer().Length() == 0);
}

void TestQueryLoaderRead()
{
	Lt::Sql::QueryLoader queryLoader;

	LT_TEST_EQUAL(queryLoader.Load("TestFiles/Query.txt") == true);

	LT_TEST_EQUAL(queryLoader.Buffer().Length() == 33);

	LT_TEST_EQUAL(queryLoader.Buffer() == "SELECT * FROM users WHERE id = 42");
}

int main()
{
	TestQueryLoaderInit();
	TestQueryLoaderRead();

	return 0;
}