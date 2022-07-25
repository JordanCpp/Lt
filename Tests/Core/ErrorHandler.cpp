#include <Lt/Core/TestEqual.hpp>
#include <Lt/Core/ErrorHandler.hpp>

void TestCoreErrorHandlerInit()
{
	Lt::Core::ErrorHandler errorHandler;

	LT_TEST_EQUAL(errorHandler.Ok() == true);
	LT_TEST_EQUAL(errorHandler.Error() == false);
}

void TestCoreErrorHandlerMessage()
{
	Lt::Core::ErrorHandler errorHandler;

	LT_TEST_EQUAL(errorHandler.Error() == false);

	errorHandler.Message("Error!");

	LT_TEST_EQUAL(errorHandler.Error() == true);
	LT_TEST_EQUAL(Lt::Chars::Equal(errorHandler.Message(), "Error!") == true);

	errorHandler.Reset();

	LT_TEST_EQUAL(errorHandler.Error() == false);
	LT_TEST_EQUAL(Lt::Chars::Equal(errorHandler.Message(), "") == true);
}

void TestCoreErrorHandlerAppend()
{
	Lt::Core::ErrorHandler errorHandler;

	LT_TEST_EQUAL(errorHandler.Error() == false);

	errorHandler.Message("Error!");
	errorHandler.Append("Error!");

	LT_TEST_EQUAL(errorHandler.Error() == true);
	LT_TEST_EQUAL(Lt::Chars::Equal(errorHandler.Message(), "Error!Error!") == true);

	errorHandler.Reset();

	LT_TEST_EQUAL(errorHandler.Error() == false);
	LT_TEST_EQUAL(Lt::Chars::Equal(errorHandler.Message(), "") == true);
}

int main()
{
	TestCoreErrorHandlerInit();
	TestCoreErrorHandlerMessage();
	TestCoreErrorHandlerAppend();

	return 0;
}