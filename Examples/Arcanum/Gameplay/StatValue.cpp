#include "StatValue.hpp"

Lt::usize Arcanum::Gameplay::StatValue::Value()
{
	return _Value;
}

Lt::usize Arcanum::Gameplay::StatValue::Number()
{
	return _Number;
}

Lt::usize Arcanum::Gameplay::StatValue::Percent()
{
	return _Percent;
}

void Arcanum::Gameplay::StatValue::Value(Lt::usize value)
{
	_Value = value;
}

void Arcanum::Gameplay::StatValue::Number(Lt::usize value)
{
	_Number = value;
}

void Arcanum::Gameplay::StatValue::Percent(Lt::usize value)
{
	_Percent = value;
}