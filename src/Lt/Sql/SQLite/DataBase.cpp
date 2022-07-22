#include <Lt/Sql/DataBase.hpp>

bool Lt::Sql::DataBase::Open(const char* path)
{
	return sqlite3_open(path, &_db) == SQLITE_OK;
}

void Lt::Sql::DataBase::Close()
{
	sqlite3_close(_db);
}

Lt::Sql::DataBase::~DataBase()
{
	Close();
}