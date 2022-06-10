#include <Lt/Core/TestEqual.hpp>
#include <Lt/Core/Types.hpp>

void TestTypesNullPtr()
{
	LT_TEST_EQUAL(nullptr == 0);
}

void TestTypesSize8()
{
	LT_TEST_EQUAL(sizeof(Lt::u8) == 1);
	LT_TEST_EQUAL(sizeof(Lt::i8) == 1);
}

void TestTypesSize16()
{
	LT_TEST_EQUAL(sizeof(Lt::u16) == 2);
	LT_TEST_EQUAL(sizeof(Lt::i16) == 2);
}

void TestTypesSize32()
{
	LT_TEST_EQUAL(sizeof(Lt::u32) == 4);
	LT_TEST_EQUAL(sizeof(Lt::i32) == 4);
}

void TestTypesSizeMax()
{
#if defined(LT_CONFIG_CPU_64)
	LT_TEST_EQUAL(sizeof(Lt::usize) == 8);
	LT_TEST_EQUAL(sizeof(Lt::isize) == 8);
#else
	LT_TEST_EQUAL(sizeof(Lt::usize) == 4);
	LT_TEST_EQUAL(sizeof(Lt::isize) == 4);
#endif
}

int main()
{
	TestTypesNullPtr();
	TestTypesSize8();
	TestTypesSize16();
	TestTypesSize32();
	TestTypesSizeMax();

	return 0;
}