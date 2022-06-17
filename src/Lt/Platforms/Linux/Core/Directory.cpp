#include <Lt/Platforms/Linux/Core/Directory.hpp>

bool Lt::Core::Linux::Directory::Open(const char *path)
{
    return false;
}

void Lt::Core::Linux::Directory::Close()
{
}

bool Lt::Core::Linux::Directory::Next(Lt::Core::FileInfo &fileInfo)
{
    return false;
}