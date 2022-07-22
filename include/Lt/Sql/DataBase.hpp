#ifndef Lt_Sql_DataBase_hpp
#define Lt_Sql_DataBase_hpp

#include <Lt/Core/Types.hpp>
#include <Lt/Sql/SQLite/sqlite3.h>

namespace Lt
{
	namespace Sql
	{
		class DataBase
		{
		public:
			bool Open(const char* path);
			void Close();
			~DataBase();
		//private:
			sqlite3* _db;
			int _rc;
		};
	}
}

#endif