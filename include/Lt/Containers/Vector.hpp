#ifndef Lt_Containers_Vector_hpp
#define Lt_Containers_Vector_hpp

#include <Lt/Allocators/Allocator.hpp>
#include <Lt/Core/Assert.hpp>
#include <Lt/Core/New.hpp>

namespace Lt
{
	namespace Containers
	{
		template<typename TYPE>
		class Vector
		{
		public:
			Vector():
				_Capacity(0),
				_Position(0),
				_Content(nullptr),
				_Allocator(nullptr)
			{
			}

			Vector(Lt::Allocators::Allocator* allocator) :
				_Capacity(0),
				_Position(0),
				_Content(nullptr),
				_Allocator(allocator)
			{
			}

			TYPE* Allocate(Lt::usize count)
			{
				if (_Allocator)
					return new (_Allocator->Allocate(sizeof(TYPE) * count)) TYPE[count];
				else
					return new TYPE[count];
			}

			void Deallocate(TYPE* ptr)
			{
				if (_Allocator)
					_Allocator->Deallocate(ptr);
				else
					delete[] ptr;
			}

			Lt::usize Capacity()
			{
				return _Capacity;
			}

			Lt::usize Length()
			{
				return _Position;
			}

			Lt::Allocators::Allocator* Allocator()
			{
				return _Allocator;
			}

			TYPE* Content()
			{
				return _Content;
			}

			void Reserve(Lt::usize count)
			{
				if (count > _Capacity)
				{
					TYPE* p = Allocate(count);

					for (Lt::usize i = 0; i < _Position; i++)
					{
						p[i] = _Content[i];
					}

					if (_Content != nullptr)
						Deallocate(_Content);

					_Content = p;

					_Capacity = count;
				}
			}

			void Resize(Lt::usize count)
			{
				Reserve(count);

				_Position = count;
			}

			const TYPE& operator[](Lt::usize index)
			{
				LT_ASSERT(index <= _Capacity);

				return _Content[index];
			}

			void Append(const TYPE& element)
			{
				if (_Capacity == 0)
					Reserve(2);
				else if (_Position + 1 > _Capacity)
					Reserve(_Capacity * 2);

				_Content[_Position] = element;

				_Position++;
			}

			void Clear()
			{
				_Position = 0;
			}
		private:
			Lt::usize _Capacity;
			Lt::usize _Position;
			TYPE* _Content;
			Lt::Allocators::Allocator* _Allocator;
		};
	}
}

#endif   