#include "Perk.hpp"

Arcanum::Gameplay::Perk::Perk()
{
}

void Arcanum::Gameplay::Perk::Add(Arcanum::Gameplay::Attribute& attribute)
{
	_Attributes.Append(attribute);
}

Lt::usize Arcanum::Gameplay::Perk::Id(Lt::usize index)
{
	return _Attributes[index].Id();
}

Lt::usize Arcanum::Gameplay::Perk::Number(Lt::usize index)
{
	return _Attributes[index].Number();
}

Lt::usize Arcanum::Gameplay::Perk::Percent(Lt::usize index)
{
	return _Attributes[index].Percent();
}

Lt::usize Arcanum::Gameplay::Perk::Length()
{
	return _Attributes.Length();
}

Lt::usize Arcanum::Gameplay::Perk::Capacity()
{
	return _Attributes.Capacity();
}