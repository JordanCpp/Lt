#ifndef Lt_Containers_CircularBuffer_hpp
#define Lt_Containers_CircularBuffer_hpp

#include <Lt/Core/Types.hpp>

namespace Lt
{
	namespace Containers
	{
		template<typename TYPE, Lt::usize COUNT>
		class CircularBuffer
		{
		public:
			CircularBuffer() :
				_Capacity(COUNT),
				_Head(_Capacity - 1),
				_Tail(0),
				_Length(0)
			{
				for (Lt::usize i = 0; i < _Capacity; i++)
				{
					_Content[i] = TYPE();
				}
			}

			bool IsEmpty()
			{
				 return _Length == 0;
			}

			bool IsFull()
			{
				return _Length == _Capacity;
			}

			Lt::usize NextPosition(Lt::usize position)
			{
				return (position + 1) % _Capacity;
			}

			bool Dequeue(TYPE& element)
			{
				if (!IsEmpty())
				{
					element = _Content[_Tail];
					_Tail = NextPosition(_Tail);
					_Length--;

					return true;
				}

				return false;
			}

			void Enqueue(const TYPE& element)
			{
				_Head = NextPosition(_Head);

				_Content[_Head] = element;

				if (IsFull())
					_Tail = NextPosition(_Tail);
				else
					_Length++;
			}
		private:
			TYPE _Content[COUNT];
			Lt::usize _Head;
			Lt::usize _Tail;
			Lt::usize _Length;
			Lt::usize _Capacity;
		};
	}
}

#endif   