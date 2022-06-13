#include <Lt/Core/TextFile.hpp>

Lt::Core::TextFile::~TextFile()
{
	Close();
}

bool Lt::Core::TextFile::Open(const char* path)
{
	return _File.Open(path, Lt::Core::BinaryFile::Reading);
}

void Lt::Core::TextFile::Close()
{
	_File.Close();
}

char Lt::Core::TextFile::Read()
{
	Lt::u8 result = 0;
	
	_File.Read(&result, 1);

	return (char)result;
}

bool Lt::Core::TextFile::Eof()
{
	return _File.Eof();
}