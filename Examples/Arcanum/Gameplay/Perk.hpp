#ifndef Arcanum_Gameplay_Perk_hpp
#define Arcanum_Gameplay_Perk_hpp

#include <Lt/Containers/StaticVector.hpp>
#include "Attribute.hpp"

namespace Arcanum
{
	namespace Gameplay
	{
		class Perk
		{
		public:
			enum
			{
				Max = 8
			};
			Perk();
			void Add(Arcanum::Gameplay::Attribute& attribute);
			Lt::usize Id(Lt::usize index);
			Lt::usize Number(Lt::usize index);
			Lt::usize Percent(Lt::usize index);
			Lt::usize Length();
			Lt::usize Capacity();
		private:
			Lt::Containers::StaticVector<Arcanum::Gameplay::Attribute, Arcanum::Gameplay::Perk::Max> _Attributes;
		};
	}
}

#endif   