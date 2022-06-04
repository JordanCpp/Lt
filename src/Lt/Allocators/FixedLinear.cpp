#include <Lt/Allocators/FixedLinear.hpp>
#include <Lt/Core/Assert.hpp>

Lt::Allocators::FixedLinear::FixedLinear(Lt::usize bytes, Lt::Allocators::Allocator* allocator):
	_Capacity(bytes),
	_Position(0),
	_Content(nullptr),
	_Allocator(allocator)
{
	if (_Allocator)
		_Content = (Lt::u8*)_Allocator->Allocate(_Capacity);
	else
		_Content = new Lt::u8[_Capacity];
}

Lt::Allocators::FixedLinear::~FixedLinear()
{
	if (_Allocator)
		_Allocator->Deallocate(_Content);
	else
		delete[] _Content;
}

void* Lt::Allocators::FixedLinear::Allocate(Lt::usize bytes)
{
	Lt_Core_Assert(bytes > 0);

	Lt_Core_Assert(_Position + bytes <= _Capacity);

	void* result = _Content + _Position;

	_Position += bytes;

	return result;
}

void Lt::Allocators::FixedLinear::Deallocate(void* ptr)
{
	Lt_Core_Assert(ptr != nullptr);
}