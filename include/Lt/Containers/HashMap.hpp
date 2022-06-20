#ifndef Lt_Containers_HashMap_hpp
#define Lt_Containers_HashMap_hpp

#include <Lt/Core/Assert.hpp>
#include <Lt/Containers/StaticString.hpp>
#include <Lt/Allocators/Allocator.hpp>

namespace Lt
{
	namespace Containers
	{
		template<typename TYPE>
		class HashNode
		{
		public:
			HashNode(const char* key):
				Next(nullptr),
				Prev(nullptr),
				_Key(key),
				Content(TYPE())
			{
			}

			const char* Key()
			{
				return _Key.Content();
			}

			HashNode<TYPE>* Next;
			HashNode<TYPE>* Prev;
			Lt::Containers::StaticString<64> _Key;
			TYPE Content;
		};

		template<typename TYPE>
		class HashList
		{
		public:
			HashNode<TYPE>* Head;
			HashNode<TYPE>* Tail;

			HashList()
			{
				Head = nullptr;
				Tail = nullptr;
			}

			~HashList()
			{
				HashNode<TYPE>* i = Head;
				HashNode<TYPE>* next = nullptr;

				while (i)
				{
					next = i->Next;
					i = next;
				}

				Head = nullptr;
				Tail = nullptr;
			}

			void Append(HashNode<TYPE>& element)
			{
				Append(element);
			}

			void Append(HashNode<TYPE>* element)
			{
				element->Next = nullptr;
				element->Prev = Tail;

				if (Tail)
				{
					Tail->Next = element;
				}

				Tail = element;

				if (Head == nullptr)
				{
					Head = element;
				}
			}
		};

		template<typename TYPE, Lt::usize COUNT>
		class HashMap
		{
		public:
			HashMap():
				_Capacity(COUNT)
			{
				_List = new Lt::Containers::HashList<TYPE>[_Capacity];
			}

			~HashMap()
			{
				delete[] _List;
			}

			Lt::usize Jenkins(const char* key, size_t len)
			{
				Lt::usize hash, i;

				for (hash = i = 0; i < len; ++i)
				{
					hash += key[i];
					hash += (hash << 10);
					hash ^= (hash >> 6);
				}

				hash += (hash << 3);
				hash ^= (hash >> 11);
				hash += (hash << 15);

				return hash;
			}

			Lt::usize Hashed(const char* key)
			{
				return Jenkins(key, Lt::Chars::Length(key)) % _Capacity;
			}

			HashNode<TYPE>* Find(const char* key)
			{
				Lt::usize h = Hashed(key);

				for (Lt::Containers::HashNode<TYPE>* i = _List[h].Head; i != nullptr; i = i->Next)
				{
					if (i->_Key == key)
						return i;
				}

				return nullptr;
			}

			void Append(HashNode<TYPE>* element)
			{
				Lt::usize h = Hashed(element->Key());

				_List[h].Append(element);
			}
		private:
			Lt::usize _Capacity;
			Lt::Containers::HashList<TYPE>* _List;
		};
	}
}

#endif   