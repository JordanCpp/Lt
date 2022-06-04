#ifndef Lt_Allocators_FixedLinear_hpp
#define Lt_Allocators_FixedLinear_hpp

#include <Lt/Allocators/Allocator.hpp>

namespace Lt
{
	namespace Allocators
	{
		class FixedLinear : public Lt::Allocators::Allocator
		{
		public:
			FixedLinear(Lt::usize bytes, Lt::Allocators::Allocator* allocator);
			~FixedLinear();
			void* Allocate(Lt::usize bytes);
			void Deallocate(void* ptr);
		private:
			Lt::usize _Capacity;
			Lt::usize _Position;
			Lt::u8* _Content;
			Lt::Allocators::Allocator* _Allocator;
		};
	}
}

#endif  