#include <Lt/Core/TestEqual.hpp>
#include <Lt/Core/Limits.hpp>

int main()
{
	LT_TEST_EQUAL(Lt::Core::Limits::i8Min < Lt::Core::Limits::i8Max);
	LT_TEST_EQUAL(Lt::Core::Limits::u8Min < Lt::Core::Limits::u8Max);

	LT_TEST_EQUAL(Lt::Core::Limits::i16Min < Lt::Core::Limits::i16Max);
	LT_TEST_EQUAL(Lt::Core::Limits::u16Min < Lt::Core::Limits::u16Max);

	LT_TEST_EQUAL(Lt::Core::Limits::i32Min < Lt::Core::Limits::i32Max);
	LT_TEST_EQUAL(Lt::Core::Limits::u32Min < Lt::Core::Limits::u32Max);

	LT_TEST_EQUAL(Lt::Core::Limits::isizeMin < Lt::Core::Limits::isizeMax);
	LT_TEST_EQUAL(Lt::Core::Limits::usizeMin < Lt::Core::Limits::usizeMax);

	return 0;
}