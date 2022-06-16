#ifndef Lt_Events_Event_hpp
#define Lt_Events_Event_hpp

#include <Lt/Core/Types.hpp>

namespace Lt
{
	namespace Events
	{
		enum
		{
			IsQuit = 1,
			IsMouseMove,
			IsMouseClick
		};

		class Quit
		{
		public:
			Lt::u8 Type;
		};

		class Mouse
		{

		public:
			enum
			{
				ButtonLeft,
				ButtonRight
			};

			enum
			{
				StateUp,
				StateDown
			};

			Lt::u8 Type;
			Lt::u32 PosX;
			Lt::u32 PosY;
			Lt::u8 State;
			Lt::u8 Button;
		};

		class Event
		{
		public:
			union
			{
				Lt::u8 Type;
				Events::Quit Quit;
				Events::Mouse Mouse;
			};
		};
	}
}

#endif