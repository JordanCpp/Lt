#ifndef Lt_Containers_Array_hpp
#define Lt_Containers_Array_hpp

#include <Lt/Core/Assert.hpp>

namespace Lt
{
	namespace Containers
	{
		template<typename TYPE, Lt::usize COUNT>
		class Array
		{
		public:
			Array() :
				_Capacity(COUNT)
			{
				for (Lt::usize i = 0; i < _Capacity; i++)
					_Content[i] = TYPE();
			}

			Lt::usize Length()
			{
				return _Capacity;
			}

			TYPE* Content()
			{
				return _Content;
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

			void Clear()
			{
				_Position = 0;
			}
		private:
			Lt::usize _Capacity;
			TYPE _Content[COUNT];
		};
	}
}

#endif   