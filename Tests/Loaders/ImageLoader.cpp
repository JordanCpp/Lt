#include <Lt/Core/TestEqual.hpp>
#include <Lt/Loaders/ImageLoader.hpp>
#include <Lt/Allocators/FixedLinear.hpp>

void TestGraphicsImageLoaderInit()
{
	Lt::Core::ErrorHandler errorHandler;

	const Lt::usize bytes = Lt::Allocators::Allocator::Mb * 1;
	Lt::Allocators::FixedLinear allocator(bytes);

	Lt::Loaders::ImageLoader imageLoader(&errorHandler, &allocator);

	LT_TEST_EQUAL(errorHandler.Error() == false);
	LT_TEST_EQUAL(imageLoader.BytesPerPixel() == 0);
	LT_TEST_EQUAL(imageLoader.Size().PosX() == 0);
	LT_TEST_EQUAL(imageLoader.Size().PosY() == 0);
	LT_TEST_EQUAL(imageLoader.Pixels() == nullptr);
}

void TestGraphicsImageLoaderLoad()
{
	Lt::Core::ErrorHandler errorHandler;

	const Lt::usize bytes = Lt::Allocators::Allocator::Mb * 1;
	Lt::Allocators::FixedLinear allocator(bytes);

	Lt::Loaders::ImageLoader imageLoader(&errorHandler, &allocator);

	imageLoader.Load("TestFiles/1182.jpg");

	LT_TEST_EQUAL(errorHandler.Error() == false);
	LT_TEST_EQUAL(imageLoader.BytesPerPixel() == 3);
	LT_TEST_EQUAL(imageLoader.Size().PosX() == 576);
	LT_TEST_EQUAL(imageLoader.Size().PosY() == 324);
	LT_TEST_EQUAL(imageLoader.Pixels() != nullptr);
	LT_TEST_EQUAL(allocator.UsedBytes() >= 576 * 324 * 4);
}

void TestGraphicsImageLoaderClear()
{
	Lt::Core::ErrorHandler errorHandler;

	const Lt::usize bytes = Lt::Allocators::Allocator::Mb * 1;
	Lt::Allocators::FixedLinear allocator(bytes);

	Lt::Loaders::ImageLoader imageLoader(&errorHandler, &allocator);

	imageLoader.Load("TestFiles/1182.jpg");
	imageLoader.Clear();

	LT_TEST_EQUAL(errorHandler.Error() == false);
	LT_TEST_EQUAL(imageLoader.BytesPerPixel() == 0);
	LT_TEST_EQUAL(imageLoader.Size().PosX() == 0);
	LT_TEST_EQUAL(imageLoader.Size().PosY() == 0);
	LT_TEST_EQUAL(imageLoader.Pixels() == nullptr);
	LT_TEST_EQUAL(allocator.UsedBytes() == 0);
}

int main()
{
	TestGraphicsImageLoaderInit();
	TestGraphicsImageLoaderLoad();
	TestGraphicsImageLoaderClear();

	return 0;
}