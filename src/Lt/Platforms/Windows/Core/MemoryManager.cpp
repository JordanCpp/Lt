#include <Lt/Platforms/Windows/Core/MemoryManager.hpp>
#include <Lt/Core/Assert.hpp>

MemoryManager::MemoryManager()
{
	_Heap = HeapCreate(0, 0x01000, 0);

	LT_ASSERT(_Heap != nullptr);
}

MemoryManager::~MemoryManager()
{
	LT_ASSERT(HeapDestroy(_Heap) != 0);
}

void* MemoryManager::Allocate(Lt::usize bytes)
{
	LT_ASSERT(bytes > 0);

	void* result = HeapAlloc(_Heap, 0, bytes);

	LT_ASSERT(result != nullptr);

	return result;
}

void MemoryManager::Deallocate(void* ptr)
{
	LT_ASSERT(ptr != nullptr);

	LT_ASSERT(HeapFree(_Heap, 0, ptr) != 0);
}