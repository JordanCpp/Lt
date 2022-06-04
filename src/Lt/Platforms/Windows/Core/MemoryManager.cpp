#include <Lt/Platforms/Windows/Core/MemoryManager.hpp>
#include <Lt/Core/Assert.hpp>

MemoryManager::MemoryManager()
{
	_Heap = HeapCreate(0, 0x01000, 0);

	Lt_Core_Assert(_Heap != nullptr);
}

MemoryManager::~MemoryManager()
{
	Lt_Core_Assert(HeapDestroy(_Heap) != 0);
}

void* MemoryManager::Allocate(Lt::usize bytes)
{
	Lt_Core_Assert(bytes > 0);

	void* result = HeapAlloc(_Heap, 0, bytes);

	Lt_Core_Assert(result != nullptr);

	return result;
}

void MemoryManager::Deallocate(void* ptr)
{
	Lt_Core_Assert(ptr != nullptr);

	Lt_Core_Assert(HeapFree(_Heap, 0, ptr) != 0);
}