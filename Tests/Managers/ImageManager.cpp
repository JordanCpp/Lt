#include <Lt/Core/TestEqual.hpp>
#include <Lt/Managers/ImageManager.hpp>
#include <Lt/Allocators/FixedLinear.hpp>

void TestManagersImage()
{
	Lt::Managers::PathManager path("TestFiles/");

	Lt::Allocators::FixedLinear forLoader(Lt::Allocators::Allocator::Mb * 1);
	Lt::Allocators::FixedLinear forManager(Lt::Allocators::Allocator::Mb * 4);

	Lt::Core::ErrorHandler errorHandler;

	Lt::Loaders::ImageLoader loader(&errorHandler, &forLoader);

	Lt::Factories::ImageFactory factory(&forManager, &loader);

	Lt::Managers::ImageManager manager(&path, &factory);

	Lt::Graphics::CpuImage* image = manager.Get("", "1182.jpg");

	LT_TEST_EQUAL(image->BytesPerPixel() == 3);
	LT_TEST_EQUAL(image->Size().PosX() == 576);
	LT_TEST_EQUAL(image->Size().PosY() == 324);
	LT_TEST_EQUAL(image->Pixels() != nullptr);
}

int main()
{
	TestManagersImage();

	return 0;
}