#ifndef Lt_Containers_BasicString_hpp
#define Lt_Containers_BasicString_hpp

#include <Lt/Allocators/Allocator.hpp>

namespace Lt
{
	namespace Containers
	{
		template<typename TYPE>
		class BasicString
		{
		public:
			~BasicString()
			{
				if (_Content)
					Deallocate(_Content);
			}

			BasicString(Lt::Allocators::Allocator* allocator):
				_Capacity(0),
				_Position(0),
				_Content(nullptr),
				_Allocator(allocator)
			{
			}

			BasicString() :
				_Capacity(0),
				_Position(0),
				_Content(nullptr),
				_Allocator(nullptr)
			{
			}

			Lt::usize Length()
			{
				return _Position;
			}

			Lt::usize Capacity()
			{
				return _Capacity;
			}

			void Reserve(Lt::usize count)
			{
				if (count > Capacity())
				{
					_Capacity = count + 1;

					char* p = Allocate(_Capacity);

					for (Lt::usize i = 0; i < _Position; i++)
					{
						p[i] = _Content[i];
					}

					Deallocate(_Content);

					_Content = p;

					p[_Position] = '\0';
				}
			}
		private:
			char* Allocate(Lt::usize count)
			{
				if (_Allocator)
					return new (_Allocator->Allocate(sizeof(TYPE) * count)) TYPE[count];
				else
					return new TYPE[count];
			}

			void Deallocate(char* ptr)
			{
				if (_Allocator)
					_Allocator->Deallocate(ptr);
				else
					delete[] ptr;
			}
			Lt::usize _Capacity;
			Lt::usize _Position;
			TYPE _Content;
			Lt::Allocators::Allocator* _Allocator;
		};
	}
}

#endif    