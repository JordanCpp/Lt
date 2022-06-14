#include <Lt/Platforms/Windows/Core/Directory.hpp>

bool Lt::Core::Directory::Open(const char* path)
{
    _File = FindFirstFile(path, &_Data);

    return _File != INVALID_HANDLE_VALUE;
}

void Lt::Core::Directory::Close()
{
    FindClose(_File);
}

bool Lt::Core::Directory::Next(Lt::Core::FileInfo& fileInfo)
{

    BOOL result = FindNextFile(_File, &_Data);

    if (result)
    {
        fileInfo.Name(_Data.cFileName);
    }

    return result;
}