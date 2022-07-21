#include "Attribute.hpp"

Arcanum::Gameplay::Attribute::Attribute() :
	_Id(0),
	_Number(0),
	_Percent(0)
{
}

Arcanum::Gameplay::Attribute::Attribute(Lt::usize id, Lt::isize number, Lt::isize percent) :
	_Id(id),
	_Number(number),
	_Percent(percent)
{
}

Lt::usize Arcanum::Gameplay::Attribute::Id()
{
	return _Id;
}

Lt::isize Arcanum::Gameplay::Attribute::Number()
{
	return _Number;
}

Lt::isize Arcanum::Gameplay::Attribute::Percent()
{
	return _Percent;
}

void Arcanum::Gameplay::Attribute::Id(Lt::usize value)
{
	_Id = value;
}

void Arcanum::Gameplay::Attribute::Number(Lt::isize value)
{
	_Number = value;
}

void Arcanum::Gameplay::Attribute::Percent(Lt::isize value)
{
	_Percent = value;
}