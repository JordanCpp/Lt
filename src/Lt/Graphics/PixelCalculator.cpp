#include <Lt/Graphics/PixelCalculator.hpp>
#include <Lt/Core/Assert.hpp>

Lt::usize Lt::Graphics::PixelCalculator::Calc(const Lt::Graphics::Point2u& size, Lt::u8 BytesPerPixel)
{
	LT_ASSERT(size.PosX() > 0);
	LT_ASSERT(size.PosY() > 0);
	LT_ASSERT(BytesPerPixel > 0 && BytesPerPixel <= 4);

	return size.PosX() * size.PosY() * BytesPerPixel;
}