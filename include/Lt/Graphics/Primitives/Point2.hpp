#ifndef Lt_Graphics_Point2_hpp
#define Lt_Graphics_Point2_hpp

namespace Lt
{
	namespace Graphics
	{
		template<typename TYPE>
		class Point2
		{
		public:
			Point2() :
				_PosX(0),
				_PosY(0)
			{
			}

			Point2(const TYPE& x, const TYPE& y) :
				_PosX(x),
				_PosY(y)
			{
			}

			const TYPE& PosX() const
			{
				return _PosX;
			}

			const TYPE& PosY() const
			{
				return _PosY;
			}

			void Pos(const TYPE& x, const TYPE& y)
			{
				_PosX = x;
				_PosY = y;
			}

			TYPE _PosX;
			TYPE _PosY;
		};
	}
}

#endif    