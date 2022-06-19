#ifndef Lt_Containers_List_hpp
#define Lt_Containers_List_hpp

#include <Lt/Core/Assert.hpp>

namespace Lt
{
	namespace Containers
	{
		template<typename TYPE>
		class ListNode
		{
		public:
			ListNode()
			{
				Next = nullptr;
				Prev = nullptr;
				Content = TYPE();
			}

			ListNode<TYPE>* Next;
			ListNode<TYPE>* Prev;
			TYPE Content;
		};

		template<typename TYPE>
		class List
		{
		public:
			ListNode<TYPE> * Head;
			ListNode<TYPE> * Tail;

			List()
			{
				Head = nullptr;
				Tail = nullptr;
			}

			~List()
			{
				ListNode<TYPE>* i = Head;
				ListNode<TYPE>* next = nullptr;

				while (i) 
				{
					next = i->Next;
					i = next;
				}

				Head = nullptr;
				Tail = nullptr;
			}

			void Append(ListNode<TYPE>& element)
			{
				Append(element);
			}

			void Append(ListNode<TYPE>* element)
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
	}
}

#endif   