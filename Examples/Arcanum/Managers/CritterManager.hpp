#ifndef Arcanum_Game_CritterManager_hpp
#define Arcanum_Game_CritterManager_hpp

#include <Lt/Allocators/Allocator.hpp>
#include "../Game/Critter.hpp"

namespace Arcanum
{
	namespace Managers
	{
		class CritterManager
		{
		public:
			CritterManager(Lt::Allocators::Allocator* allocator);
			Arcanum::Game::Critter* Get();
		private:
			Lt::Allocators::Allocator* _Allocator;
		};
	}
}

#endif   