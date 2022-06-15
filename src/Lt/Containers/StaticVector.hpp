#ifndef Lt_Containers_StaticVector_hpp
#define Lt_Containers_StaticVector_hpp

#include <Lt/Core/Assert.hpp>

namespace Lt
{
	namespace Containers
	{
		template<typename TYPE, Lt::usize COUNT>
		class StaticVector
		{
		public:
			StaticVector() :
				_Capacity(COUNT),
				_Position(0)
			{
				for (Lt::usize i = 0; i < _Capacity; i++)
				{
					_Content[i] = TYPE();
				}
			}

			Lt::usize Capacity()
			{
				return _Capacity;
			}

			Lt::usize Length()
			{
				return _Position;
			}

			TYPE* Content()
			{
				return _Content;
			}

			void Clear()
			{
				_Position = 0;
			}

			const TYPE& operator[](Lt::usize index) const
			{
				LT_ASSERT(index <= _Capacity);

				return _Content[index];
			}


			TYPE& operator[](Lt::usize index)
			{
				LT_ASSERT(index <= _Capacity);

				return _Content[index];
			}

			void Append(const TYPE& element)
			{
				if (_Position + 1 <= _Capacity)
				{
					_Content[_Position] = element;

					_Position++;
				}
			}
		private:
			Lt::usize _Capacity;
			Lt::usize _Position;
			TYPE _Content[COUNT];
		};
	}
}

#endif   