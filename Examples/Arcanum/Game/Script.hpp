#ifndef Arcanum_Game_Script_hpp
#define Arcanum_Game_Script_hpp

namespace Arcanum
{
	namespace Game
	{
		class Script
		{
		public:
			virtual void MapEnter() = 0;
			virtual void MapExit() = 0;
			virtual void MapUpdate() = 0;
		private:
		};
	}
}

#endif   