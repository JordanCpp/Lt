#include <Lt/Core/TestEqual.hpp>
#include <Lt/Loaders/Image.hpp>
#include <Lt/Allocators/FixedLinear.hpp>

void TestGraphicsImageLoaderInit()
{
	Lt::Core::ErrorHandler errorHandler;

	const Lt::usize bytes = Lt::Allocators::Allocator::Mb * 1;
	Lt::Allocators::FixedLinear allocator(bytes);

	Lt::Loaders::Image imageLoader(&errorHandler, &allocator);

	LT_TEST_EQUAL(errorHandler.IsError() == false);
	LT_TEST_EQUAL(imageLoader.Channels() == 0);
	LT_TEST_EQUAL(imageLoader.Size().PosX() == 0);
	LT_TEST_EQUAL(imageLoader.Size().PosY() == 0);
	LT_TEST_EQUAL(imageLoader.Pixels() == nullptr);
}

void TestGraphicsImageLoaderLoad()
{
	Lt::Core::ErrorHandler errorHandler;

	const Lt::usize bytes = Lt::Allocators::Allocator::Mb * 1;
	Lt::Allocators::FixedLinear allocator(bytes);

	Lt::Loaders::Image imageLoader(&errorHandler, &allocator);

	imageLoader.Load("TestFiles/1182.jpg");

	LT_TEST_EQUAL(errorHandler.IsError() == false);
	LT_TEST_EQUAL(imageLoader.Channels() == 3);
	LT_TEST_EQUAL(imageLoader.Size().PosX() == 576);
	LT_TEST_EQUAL(imageLoader.Size().PosY() == 324);
	LT_TEST_EQUAL(imageLoader.Pixels() != nullptr);
	LT_TEST_EQUAL(allocator.UsedBytes() >= 576 * 324 * 3);
}

int main()
{
	TestGraphicsImageLoaderInit();
	TestGraphicsImageLoaderLoad();

	return 0;
}