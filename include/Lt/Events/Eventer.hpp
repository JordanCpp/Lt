#ifndef Lt_Events_Eventer_hpp
#define Lt_Events_Eventer_hpp

#include <Lt/Events/Event.hpp>
#include <Lt/Containers/CircularBuffer.hpp>

namespace Lt
{
	namespace Events
	{
		class Eventer
		{
		public:
			enum
			{
				Max = 128
			};
			Eventer();
			void Push(Lt::Events::Event& event);
			bool Pop(Lt::Events::Event& event);
			bool Running();
			void Stop();
		private:
			bool _Running;
			Lt::Containers::CircularBuffer<Lt::Events::Event, Lt::Events::Eventer::Max> _Queue;
		};
	}
}

#endif