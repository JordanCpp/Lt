#ifndef Lt_Graphics_Rect2_hpp
#define Lt_Graphics_Rect2_hpp

#include <Lt/Graphics/Primitives/Point2.hpp>

namespace Lt
{
	namespace Graphics
	{
		template<typename TYPE>
		class Rect2
		{
		public:
			Rect2() :
				_Pos(0, 0),
				_Size(0, 0)
			{
			}

			Rect2(const TYPE& x, const TYPE& y, const TYPE& w, const TYPE& h) :
				_Pos(x, y),
				_Size(w, h)
			{
			}

			Rect2(const Lt::Graphics::Point2<TYPE>& pos, const Lt::Graphics::Point2<TYPE>& size) :
				_Pos(pos),
				_Size(size)
			{
			}

			const Lt::Graphics::Point2<TYPE>& Pos() const
			{
				return _Pos;
			}

			const Lt::Graphics::Point2<TYPE>& Size() const
			{
				return _Size;
			}
		private:
			Lt::Graphics::Point2<TYPE> _Pos;
			Lt::Graphics::Point2<TYPE> _Size;
		};
	}
}

#endif    