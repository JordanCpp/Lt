#include <Lt/Platforms/Linux/Core/BinaryFile.hpp>

Lt::Core::Linux::BinaryFile::BinaryFile():
	_Bytes(0),
	_Position(0)
{
}

Lt::Core::Linux::BinaryFile::~BinaryFile()
{
	Close();
}

Lt::usize Lt::Core::Linux::BinaryFile::Position()
{
	return _Position;
}

Lt::usize Lt::Core::Linux::BinaryFile::Size()
{
	return _Bytes;
}

bool Lt::Core::Linux::BinaryFile::Eof()
{
	if (_Bytes == 0)
		return true;
	else
		return _Position == _Bytes;
}

bool Lt::Core::Linux::BinaryFile::Open(const char* path, Lt::usize mode)
{
	_Bytes = 0;
	_Position = 0;

	return false;
}

void Lt::Core::Linux::BinaryFile::Close()
{
	_Bytes = 0;
	_Position = 0;
}

Lt::usize Lt::Core::Linux::BinaryFile::Read(Lt::u8* dst, Lt::usize bytes)
{
	Lt::usize result = 0;

	return result;
}