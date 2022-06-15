#include <Lt/Core/TestEqual.hpp>
#include <Lt/Core/Limits.hpp>

int main()
{
	LT_TEST_EQUAL(Lt::Core::Limits::i8Min < Lt::Core::Limits::u8Min);
	LT_TEST_EQUAL(Lt::Core::Limits::i8Max < Lt::Core::Limits::u8Max);

	LT_TEST_EQUAL(Lt::Core::Limits::i16Min < Lt::Core::Limits::u16Min);
	LT_TEST_EQUAL(Lt::Core::Limits::i16Max < Lt::Core::Limits::u16Max);

	LT_TEST_EQUAL(Lt::Core::Limits::i32Min < Lt::Core::Limits::u32Min);
	LT_TEST_EQUAL(Lt::Core::Limits::i32Max < Lt::Core::Limits::u32Max);

	LT_TEST_EQUAL(Lt::Core::Limits::isizeMin < Lt::Core::Limits::usizeMin);
	LT_TEST_EQUAL(Lt::Core::Limits::isizeMax < Lt::Core::Limits::usizeMax);

	return 0;
}