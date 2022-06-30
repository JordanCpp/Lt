#include <Lt/Core/TestEqual.hpp>
#include <Lt/Managers/ImageManager.hpp>
#include <Lt/Allocators/FixedLinear.hpp>

void TestManagersImage()
{
	Lt::Managers::Path path("TestFiles/");

	Lt::Allocators::FixedLinear forLoader(Lt::Allocators::Allocator::Mb * 1);
	Lt::Allocators::FixedLinear forManager(Lt::Allocators::Allocator::Mb * 4);

	Lt::Core::ErrorHandler errorHandler;

	Lt::Loaders::Image loader(&errorHandler, &forLoader);

	//Lt::Factories::Image Factory(&forManager, &loader);
}

int main()
{
	TestManagersImage();

	return 0;
}