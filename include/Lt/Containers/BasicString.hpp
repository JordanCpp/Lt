#ifndef Lt_Containers_BasicString_hpp
#define Lt_Containers_BasicString_hpp

#include <Lt/Allocators/Allocator.hpp>
#include <Lt/Core/Chars.hpp>

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

			Lt::Allocators::Allocator* Allocator()
			{
				return _Allocator;
			}

			const TYPE* Content() const
			{
				return _Content;
			}

			Lt::usize Length()
			{
				return _Position;
			}

			Lt::usize Capacity()
			{
				return _Capacity;
			}

			void Clear()
			{
				_Position = 0;
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

					if (_Content != nullptr)
						Deallocate(_Content);

					_Content = p;

					p[_Position] = '\0';
				}
			}

			void Append(const TYPE& element)
			{
				if (_Capacity == 0)
				{
					Reserve(2);
				}
				else if (_Position + 1 >= _Capacity)
				{
					Reserve(_Capacity * 2);
				}

				_Content[_Position] = element;

				_Position++;

				_Content[_Position] = '\0';

			}

			void Append(const TYPE* elements)
			{
				Lt::usize i = 0;

				while (elements[i] != '\0')
				{
					Append(elements[i]);

					i++;
				}
			}

			void Assign(const char * elements)
			{
				Clear();

				Append(elements);
			}

			BasicString& operator= (const char* source)
			{
				Assign(source);

				return *this;
			}

			friend bool operator==(const BasicString& a, const BasicString& b)
			{
				return Lt::Chars::Equal(a.Content(), b.Content());
			}

			friend bool operator==(const BasicString& a, const char * b)
			{
				return Lt::Chars::Equal(a.Content(), b);
			}

			friend bool operator!=(const BasicString& a, const BasicString& b)
			{
				return Lt::Chars::Compare(a.Content(), b.Content());
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
			TYPE* _Content;
			Lt::Allocators::Allocator* _Allocator;
		};
	}
}

#endif    