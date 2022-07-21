#include "CritterStats.hpp"

Lt::usize Arcanum::Gameplay::CritterStats::Value(Lt::usize index)
{
	return _Stats[index].Value();
}

Lt::usize Arcanum::Gameplay::CritterStats::Number(Lt::usize index)
{
	return _Stats[index].Number();
}

Lt::usize Arcanum::Gameplay::CritterStats::Percent(Lt::usize index)
{
	return _Stats[index].Percent();
}

void Arcanum::Gameplay::CritterStats::Value(Lt::usize index, Lt::usize value)
{
	_Stats[index].Value(value);
}

void Arcanum::Gameplay::CritterStats::Number(Lt::usize index, Lt::usize value)
{
	_Stats[index].Number(value);
}

void Arcanum::Gameplay::CritterStats::Percent(Lt::usize index, Lt::usize value)
{
	_Stats[index].Percent(value);
}