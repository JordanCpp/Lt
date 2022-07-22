#include <Lt/Sql/Statement.hpp>
#include <Lt/Core/Assert.hpp>

Lt::Sql::Statement::Statement(Lt::Sql::DataBase* dataBase) :
	_DataBase(dataBase),
	_stmt(nullptr),
	_Count(0)
{
}

Lt::Sql::Statement::~Statement()
{
	sqlite3_finalize(_stmt);
}

void Lt::Sql::Statement::Bind(const char* value)
{
	_Count++;

	sqlite3_bind_text(_stmt, _Count, value, -1, 0);
}

void Lt::Sql::Statement::Bind(Lt::isize value)
{
	_Count++;

	sqlite3_bind_int(_stmt, _Count, value);
}

bool Lt::Sql::Statement::Execute(const char* sql)
{
	if (sqlite3_prepare_v2(_DataBase->_db, sql, -1, &_stmt, 0) != SQLITE_OK) 
	{
		sqlite3_finalize(_stmt);

		return false;
	}

	return true;
}

bool Lt::Sql::Statement::Next()
{
	return sqlite3_step(_stmt) == SQLITE_ROW;
}

const Lt::u8* Lt::Sql::Statement::Get(Lt::usize index)
{
	LT_ASSERT(index <= (Lt::usize)sqlite3_column_count(_stmt));

	return sqlite3_column_text(_stmt, (int)index);
}

Lt::isize Lt::Sql::Statement::GetInt(Lt::usize index)
{
	LT_ASSERT(index <= (Lt::usize)sqlite3_column_count(_stmt));

	return sqlite3_column_int(_stmt, (int)index);
}