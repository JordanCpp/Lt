#include <Lt/Sql/QueryLoader.hpp>

bool Lt::Sql::QueryLoader::Load(const char* path)
{
	_Buffer.Clear();

	if (_Input.Open(path, Lt::Core::BinaryFile::Reading))
	{
		Lt::usize bytes = _Input.Size();

		_Buffer.Resize(bytes);

		_Input.Read((Lt::u8*)_Buffer.Content(), bytes);

		_Input.Close();

		return true;
	}

	return false;
}

const Lt::Containers::String& Lt::Sql::QueryLoader::Buffer()
{
	return _Buffer;
}