#include "Attribute.hpp"

Arcanum::Gameplay::Attribute::Attribute() :
	_Number(0),
	_Percent(0)
{
}

Lt::usize Arcanum::Gameplay::Attribute::Number()
{
	return _Number;
}

Lt::usize Arcanum::Gameplay::Attribute::Percent()
{
	return _Percent;
}

void Arcanum::Gameplay::Attribute::Number(Lt::usize value)
{
	_Number = value;
}

void Arcanum::Gameplay::Attribute::Percent(Lt::usize value)
{
	_Percent = value;
}