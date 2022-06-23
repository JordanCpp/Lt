#include <Lt/Platforms/Windows/Core/Directory.hpp>

bool Lt::Core::Windows::Directory::Create(const char* path)
{
    return CreateDirectory(path, NULL);
}

bool Lt::Core::Windows::Directory::Exist(const char* path)
{
    DWORD attr = GetFileAttributes(path);

    return (attr != INVALID_FILE_ATTRIBUTES && (attr & FILE_ATTRIBUTE_DIRECTORY));
}

bool Lt::Core::Windows::Directory::Delete(const char* path)
{
    return RemoveDirectory(path);
}

bool Lt::Core::Windows::Directory::Open(const char* path)
{
    _File = FindFirstFile(path, &_Data);

    return _File != INVALID_HANDLE_VALUE;
}

void Lt::Core::Windows::Directory::Close()
{
    FindClose(_File);
}

bool Lt::Core::Windows::Directory::Next(Lt::Core::FileInfo& fileInfo)
{

    BOOL result = FindNextFile(_File, &_Data);

    if (result)
    {
        fileInfo.Name(_Data.cFileName);
    }

    return result;
}