#include <Lt/Sql/Query.hpp>

Lt::Sql::Query::Query(const char* source)
{
	_Content = source;
}

const Lt::Containers::String& Lt::Sql::Query::Content()
{
	return _Content;
}