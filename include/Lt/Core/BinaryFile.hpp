#ifndef Lt_Core_BinaryFile_hpp
#define Lt_Core_BinaryFile_hpp

#include <Lt/Core/Config.hpp>

#if defined(LT_CONFIG_OS_WINDOWS)
#include <Lt/Platforms/Windows/Core/BinaryFile.hpp>
namespace Lt
{
	namespace Core
	{
		typedef Lt::Core::Windows::BinaryFile BinaryFile;
	}
}
#else
#error Not support: Core::BinaryFile
#endif

#endif    