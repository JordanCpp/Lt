#include <Lt/Core/TestEqual.hpp>
#include <Lt/Core/Convert.hpp>
#include <Lt/Core/Chars.hpp>

int main()
{
	Lt::Core::Convert convert;

	Lt_TestEqual(convert.IntToStr(197456) == true);

	Lt_TestEqual(Lt::Chars::Equal(convert.Result(), "197456"));

	return 0;
}