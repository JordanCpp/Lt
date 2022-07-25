#include <Lt/Core/TestEqual.hpp>
#include <Lt/Sql/Query.hpp>

void TestQueryInit()
{
	Lt::Sql::Query query("Hello world!");

	LT_TEST_EQUAL(query.Content() == "Hello world!");
}

int main()
{
	TestQueryInit();

	return 0;
}