#include <Lt/Core/TestEqual.hpp>
#include <Lt/Loaders/Image.hpp>

void TestGraphicsImageLoaderInit()
{
	Lt::Core::ErrorHandler errorHandler;
	Lt::Loaders::Image imageLoader(&errorHandler);

	LT_TEST_EQUAL(errorHandler.IsError() == false);
	LT_TEST_EQUAL(imageLoader.Channels() == 0);
	LT_TEST_EQUAL(imageLoader.Size().PosX() == 0);
	LT_TEST_EQUAL(imageLoader.Size().PosY() == 0);
	LT_TEST_EQUAL(imageLoader.Pixels() == nullptr);
}

void TestGraphicsImageLoaderLoad()
{
	Lt::Core::ErrorHandler errorHandler;
	Lt::Loaders::Image imageLoader(&errorHandler);

	imageLoader.Load("TestFiles/1182.jpg");

	LT_TEST_EQUAL(errorHandler.IsError() == false);
	LT_TEST_EQUAL(imageLoader.Channels() == 3);
	LT_TEST_EQUAL(imageLoader.Size().PosX() == 576);
	LT_TEST_EQUAL(imageLoader.Size().PosY() == 324);
	LT_TEST_EQUAL(imageLoader.Pixels() != nullptr);
}

int main()
{
	TestGraphicsImageLoaderInit();
	TestGraphicsImageLoaderLoad();

	return 0;
}