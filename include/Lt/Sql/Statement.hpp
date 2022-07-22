#ifndef Lt_Sql_Statement_hpp
#define Lt_Sql_Statement_hpp

#include <Lt/Sql/DataBase.hpp>

namespace Lt
{
	namespace Sql
	{
		class Statement
		{
		public:
			Statement(Lt::Sql::DataBase* dataBase);
			~Statement();
			void Bind(const char * value);
			void Bind(Lt::isize value);
			bool Execute(const char* sql);
			bool Next();
			const Lt::u8* Get(Lt::usize index);
			Lt::isize GetInt(Lt::usize index);
		private:
			Lt::Sql::DataBase* _DataBase;
			sqlite3_stmt* _stmt;
			Lt::usize _Count;
		};
	}
}

#endif