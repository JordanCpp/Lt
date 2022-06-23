#include <Lt/Platforms/Windows/Core/BinaryFile.hpp>

Lt::Core::Windows::BinaryFile::BinaryFile():
	_File(nullptr),
	_Bytes(0),
	_Position(0)
{
}

Lt::Core::Windows::BinaryFile::~BinaryFile()
{
	Close();
}

bool Lt::Core::Windows::BinaryFile::Create(const char* path)
{
	return CreateFile(path, 0, 0, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL) != INVALID_HANDLE_VALUE;
}

bool Lt::Core::Windows::BinaryFile::Recreate(const char* path)
{
	return CreateFile(path, 0, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL) != INVALID_HANDLE_VALUE;
}

bool Lt::Core::Windows::BinaryFile::Exist(const char* path)
{
	DWORD fileAttr = GetFileAttributes(path);

	return (0xFFFFFFFF == fileAttr && GetLastError() == ERROR_FILE_NOT_FOUND) != true;
}

bool Lt::Core::Windows::BinaryFile::Delete(const char* path)
{
	return DeleteFile(path) != 0;
}

Lt::usize Lt::Core::Windows::BinaryFile::Position()
{
	return _Position;
}

Lt::usize Lt::Core::Windows::BinaryFile::Size()
{
	return _Bytes;
}

bool Lt::Core::Windows::BinaryFile::Eof()
{
	if (_Bytes == 0)
		return true;
	else
		return _Position == _Bytes;
}

bool Lt::Core::Windows::BinaryFile::Open(const char* path, Lt::usize mode)
{
	_Bytes = 0;
	_Position = 0;

	if (mode == Lt::Core::Windows::BinaryFile::Mode::Reading)
		_File = CreateFile(path, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	else if (mode == Lt::Core::Windows::BinaryFile::Mode::Writing)
		_File = CreateFile(path, GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	else if (mode == (Lt::Core::Windows::BinaryFile::Mode::Reading | Lt::Core::Windows::BinaryFile::Mode::Writing))
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

void Lt::Core::Windows::BinaryFile::Close()
{
	_Bytes = 0;
	_Position = 0;

	if (_File != INVALID_HANDLE_VALUE)
	{
		CloseHandle(_File);
	}
}

Lt::usize Lt::Core::Windows::BinaryFile::Read(Lt::u8* dst, Lt::usize bytes)
{
	DWORD result = 0;

	if (ReadFile(_File, dst, (DWORD)bytes, &result, NULL))
	{
		_Position += result;
	}

	return result;
}

Lt::usize Lt::Core::Windows::BinaryFile::Write(Lt::u8* src, Lt::usize bytes)
{
	DWORD result = 0;

	if (WriteFile(_File, src, bytes, &result, NULL))
	{
		_Position += result;
		_Bytes += result;
	}
	
	return result;
}