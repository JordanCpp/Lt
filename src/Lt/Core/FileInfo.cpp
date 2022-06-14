#include "Lt/Core/FileInfo.hpp"

const char* Lt::Core::FileInfo::Name()
{
	return _Name.Content();
}

void Lt::Core::FileInfo::Name(const char* source)
{
	_Name.Assign(source);
}