#include <Lt/Platforms/Windows/Core/File.hpp>

Lt::Core::File::File():
	_File(nullptr),
	_Bytes(0),
	_Position(0)
{
}

Lt::Core::File::~File()
{
	Close();
}

bool Lt::Core::File::Eof()
{
	if (_Bytes == 0)
		return true;
	else
		return _Position == _Bytes;
}

bool Lt::Core::File::Open(const char* path, Lt::usize mode)
{
	_Bytes = 0;
	_Position = 0;

	if (mode == Lt::Core::File::Mode::Reading)
		_File = CreateFile(path, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	else if (mode == Lt::Core::File::Mode::Writing)
		_File = CreateFile(path, GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	else if (mode == (Lt::Core::File::Mode::Reading | Lt::Core::File::Mode::Writing))
		_File = CreateFile(path, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	else
		return false;

	if (_File != INVALID_HANDLE_VALUE)
	{
		_Bytes = GetFileSize(_File, nullptr);

		return true;
	}

	return false;
}

void Lt::Core::File::Close()
{
	if (_File != INVALID_HANDLE_VALUE)
	{
		CloseHandle(_File);
	}
}

Lt::usize Lt::Core::File::Read(Lt::u8* dst, Lt::usize bytes)
{
	DWORD result = 0;

	if (ReadFile(_File, dst, (DWORD)bytes, &result, NULL))
	{
		_Position += result;
	}

	return result;
}