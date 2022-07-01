#include <Lt/Core/New.hpp>
#include <Lt/Core/Assert.hpp>

#include <stdlib.h>

void* operator new(Lt::usize bytes)
{
	void* p = malloc(bytes);

	LT_ASSERT(p != nullptr);

	return p;
}

void operator delete(void* ptr)
{
	LT_ASSERT(ptr != nullptr);

	free(ptr);
}

void* operator new[](Lt::usize bytes)
{
	void* p = malloc(bytes);

	LT_ASSERT(p != nullptr);

	return p;
}

void operator delete[](void* ptr)
{
	LT_ASSERT(ptr != nullptr);

	free(ptr);
}

void* operator new(Lt::usize bytes, void* ptr)
{
	LT_ASSERT(ptr != nullptr);

	return ptr;
}

void operator delete(void* ptr, Lt::usize bytes)
{
	LT_ASSERT(ptr != nullptr);

	free(ptr);
}

void* operator new[](Lt::usize bytes, void* ptr)
{
	LT_ASSERT(ptr != nullptr);

	return ptr;
}

void operator delete[](void* ptr, Lt::usize bytes)
{
	LT_ASSERT(ptr != nullptr);

	free(ptr);
}