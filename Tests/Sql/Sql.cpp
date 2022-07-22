#include <Lt/Core/TestEqual.hpp>
#include <Lt/Sql/Statement.hpp>

void TestSqlDataBaseInit()
{
	Lt::Sql::DataBase db;

	LT_TEST_EQUAL(db.Open("TestFiles/Test.db") == true);
}

void TestSqlStatementSelect()
{
	Lt::Sql::DataBase db;

	LT_TEST_EQUAL(db.Open("TestFiles/Test.db") == true);

	Lt::Sql::Statement statement(&db);

	LT_TEST_EQUAL(statement.Execute("SELECT strength FROM Stats") == true);

	LT_TEST_EQUAL(statement.Next() == true);
	LT_TEST_EQUAL(statement.GetInt(0) == 7);

	LT_TEST_EQUAL(statement.Next() == true);
	LT_TEST_EQUAL(statement.GetInt(0) == 3);

	LT_TEST_EQUAL(statement.Next() == false);
}

void TestSqlStatementSelectBindInt()
{
	Lt::Sql::DataBase db;

	LT_TEST_EQUAL(db.Open("TestFiles/Test.db") == true);

	Lt::Sql::Statement statement(&db);

	LT_TEST_EQUAL(statement.Execute("SELECT strength FROM Stats WHERE id = ?") == true);

	statement.Bind(1);

	LT_TEST_EQUAL(statement.Next() == true);
	LT_TEST_EQUAL(statement.GetInt(0) == 7);

	LT_TEST_EQUAL(statement.Next() == false);
}

int main()
{
	TestSqlDataBaseInit();
	TestSqlStatementSelect();
	TestSqlStatementSelectBindInt();

	return 0;
}