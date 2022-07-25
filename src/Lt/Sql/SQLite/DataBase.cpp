#include <Lt/Sql/DataBase.hpp>

Lt::Sql::DataBase::DataBase(Lt::Core::ErrorHandler* errorHandler):
	_ErrorHandler(),
	_db(nullptr),
	_rc(0)
{
}

bool Lt::Sql::DataBase::Open(const char* path)
{
	if (sqlite3_open(path, &_db) == SQLITE_OK)
		return true;

	_ErrorHandler->Message("Not found:");
	_ErrorHandler->Append(path);

	return false;
}

void Lt::Sql::DataBase::Close()
{
	sqlite3_close(_db);
}

Lt::Sql::DataBase::~DataBase()
{
	Close();
}