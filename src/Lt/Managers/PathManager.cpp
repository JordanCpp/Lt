#include <Lt/Managers/PathManager.hpp>

Lt::Managers::PathManager::PathManager(const char* path) :
	_ShortPath(path)
{
}

const char* Lt::Managers::PathManager::Get(const char* dir, const char* file)
{
	_FullPath.Clear();
	_FullPath.Append(_ShortPath.Content());
	_FullPath.Append(dir);
	_FullPath.Append(file);

	return _FullPath.Content();
}