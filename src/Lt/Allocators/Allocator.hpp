#ifndef Lt_Allocators_Allocator_hpp
#define Lt_Allocators_Allocator_hpp

#include <Lt/Core/Types.hpp>

namespace Lt
{
	namespace Allocators
	{
		class Allocator
		{
		public:
			enum
			{
				Kb = 1024,
				Mb = Kb * 1024,
				Gb = Mb * 1024
			};
			virtual void* Allocate(Lt::usize bytes) = 0;
			virtual void Deallocate(void* ptr) = 0;
		private:
		};
	}
}

#endif    