#ifndef Lt_Sql_Query_hpp
#define Lt_Sql_Query_hpp

#include <Lt/Containers/String.hpp>

namespace Lt
{
	namespace Sql
	{
		class Query
		{
		public:
			Query(const char * source);
			const Lt::Containers::String& Content();
		private:
			Lt::Containers::String _Content;
		};
	}
}

#endif