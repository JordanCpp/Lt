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

		template<typename TYPE>
		class HashMap
		{
		public:
			HashMap(Lt::usize count):
				_Allocator(nullptr),
				_Capacity(count)
			{
				_List = new Lt::Containers::HashList<TYPE>[_Capacity];
			}

			HashMap(Lt::usize count, Lt::Allocators::Allocator* allocator) :
				_Allocator(allocator),
				_Capacity(count)
			{
				_List = new(_Allocator->Allocate(_Capacity * sizeof(TYPE))) Lt::Containers::HashList<TYPE>[_Capacity];
			}

			~HashMap()
			{
				if (_Allocator != nullptr)
					_Allocator->Deallocate(_List);
				else
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

			void Append(const char* key, TYPE element)
			{
				HashNode<TYPE>* node = nullptr;

				if (_Allocator != nullptr)
					node = new(_Allocator->Allocate(sizeof(HashNode<TYPE>))) HashNode<TYPE>(key);
				else
					node = new HashNode<TYPE>(key);

				Lt::usize h = Hashed(node->Key());

				node->Content = element;

				_List[h].Append(node);
			}

			void Append(const char* key, TYPE* element)
			{
				HashNode<TYPE>* node = nullptr;

				if (_Allocator != nullptr)
					node = new(_Allocator->Allocate(sizeof(HashNode<TYPE>))) HashNode<TYPE>(key);
				else
					node = new HashNode<TYPE>(key);

				Lt::usize h = Hashed(node->Key());

				node->Content = element;

				_List[h].Append(node);
			}
		private:
			Lt::Allocators::Allocator* _Allocator;
			Lt::usize _Capacity;
			Lt::Containers::HashList<TYPE>* _List;
		};
	}
}

#endif   