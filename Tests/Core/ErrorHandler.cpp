#include <Lt/Core/TestEqual.hpp>
#include <Lt/Core/ErrorHandler.hpp>

void TestCoreErrorHandler()
{
	Lt::Core::ErrorHandler errorHandler;

	LT_TEST_EQUAL(errorHandler.IsError() == false);

	errorHandler.Message("Error!");

	LT_TEST_EQUAL(errorHandler.IsError() == true);
	LT_TEST_EQUAL(Lt::Chars::Equal(errorHandler.Message(), "Error!") == true);

	errorHandler.Reset();

	LT_TEST_EQUAL(errorHandler.IsError() == false);
	LT_TEST_EQUAL(Lt::Chars::Equal(errorHandler.Message(), "") == true);
}

int main()
{
	TestCoreErrorHandler();

	return 0;
}