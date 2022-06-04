#include <Lt/Core/New.hpp>
#include <Lt/Platforms/Windows/Core/MemoryManager.hpp>

static MemoryManager memoryManager;

void* operator new(Lt::usize bytes)
{
	return memoryManager.Allocate(bytes);
}

void operator delete(void* ptr)
{
	memoryManager.Deallocate(ptr);
}

void* operator new[](Lt::usize bytes)
{
	return memoryManager.Allocate(bytes);
}

void operator delete[](void* ptr)
{
	memoryManager.Deallocate(ptr);
}

void* operator new(Lt::usize bytes, void* ptr)
{
	return memoryManager.Allocate(bytes);
}

void* operator new[](Lt::usize bytes, void* ptr)
{
	return memoryManager.Allocate(bytes);
}