#ifndef Lt_Sql_QueryLoader_hpp
#define Lt_Sql_QueryLoader_hpp

#include <Lt/Core/BinaryFile.hpp>
#include <Lt/Sql/Query.hpp>

namespace Lt
{
	namespace Sql
	{
		class QueryLoader
		{
		public:
			bool Load(const char * path);
			const Lt::Containers::String& Buffer();
		private:
			Lt::Core::BinaryFile _Input;
			Lt::Containers::String _Buffer;
		};
	}
}

#endif