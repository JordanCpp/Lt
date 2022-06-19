#ifndef Lt_Containers_StaticString_hpp
#define Lt_Containers_StaticString_hpp

#include <Lt/Core/Chars.hpp>
#include <Lt/Core/Assert.hpp>

namespace Lt
{
	namespace Containers
	{
		template<Lt::usize COUNT>
		class StaticString
		{
		public:
			StaticString():
				_Capacity(COUNT),
				_Position(0)
			{
				LT_ASSERT(_Capacity >= 2);
			}

			StaticString(const char * source) :
				_Capacity(COUNT),
				_Position(0)
			{
				LT_ASSERT(_Capacity >= 2);

				Assign(source);
			}

			Lt::usize Capacity()
			{
				return _Capacity - 1;
			}

			Lt::usize Length()
			{
				return _Position;
			}

			const char * Content() const
			{
				return _Content;
			}

			void Clear()
			{
				_Position = 0;
				_Content[_Position] = '\0';
			}

			void Append(const char element)
			{
				if (_Position + 1 < _Capacity)
				{
					_Content[_Position] = element;

					_Position++;

					_Content[_Position] = '\0';
				}
			}

			void Append(const char* elements)
			{
				Lt::usize i = 0;

				while (elements[i] != '\0')
				{
					Append(elements[i]);

					i++;
				}
			}

			void Assign(const char* elements)
			{
				Clear();
				Append(elements);
			}

			const char& operator[](Lt::usize index) const
			{
				LT_ASSERT(index <= _Capacity);

				return _Content[index];
			}


			char& operator[](Lt::usize index)
			{
				LT_ASSERT(index <= _Capacity);

				return _Content[index];
			}
		private:
			Lt::usize _Capacity;
			Lt::usize _Position;
			char _Content[COUNT];
		};
	}
}

#endif    