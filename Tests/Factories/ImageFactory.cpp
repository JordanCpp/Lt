#include <Lt/Core/TestEqual.hpp>
#include <Lt/Factories/ImageFactory.hpp>
#include <Lt/Allocators/FixedLinear.hpp>

void TestFactoriesImageFactory()
{
	Lt::Allocators::FixedLinear forLoader(Lt::Allocators::Allocator::Mb * 1);
	Lt::Allocators::FixedLinear forManager(Lt::Allocators::Allocator::Mb * 4);

	Lt::Core::ErrorHandler errorHandler;

	Lt::Loaders::ImageLoader loader(&errorHandler, &forLoader);

	Lt::Factories::ImageFactory factory(&forManager, &loader);

	Lt::Graphics::CpuImage* image = factory.Get("TestFiles/1182.jpg");

	LT_TEST_EQUAL(image->Channels() == 3);
	LT_TEST_EQUAL(image->Size().PosX() == 576);
	LT_TEST_EQUAL(image->Size().PosY() == 324);
	LT_TEST_EQUAL(image->Pixels() != nullptr);
}

int main()
{
	TestFactoriesImageFactory();

	return 0;
}