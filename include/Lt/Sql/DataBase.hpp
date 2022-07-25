#ifndef Lt_Sql_DataBase_hpp
#define Lt_Sql_DataBase_hpp

#include <Lt/Core/ErrorHandler.hpp>
#include <Lt/Sql/SQLite/sqlite3.h>

namespace Lt
{
	namespace Sql
	{
		class DataBase
		{
		public:
			DataBase(Lt::Core::ErrorHandler* errorHandler);
			bool Open(const char* path);
			void Close();
			~DataBase();
		//private:
			Lt::Core::ErrorHandler* _ErrorHandler;
			sqlite3* _db;
			int _rc;
		};
	}
}

#endif