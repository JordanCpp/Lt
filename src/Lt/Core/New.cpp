#include <Lt/Core/New.hpp>
#include <Lt/Core/Assert.hpp>

#include <stdlib.h>

void* operator new(Lt::usize bytes)
{
	return malloc(bytes);
}

void operator delete(void* ptr)
{
	free(ptr);
}

void* operator new[](Lt::usize bytes)
{
	return malloc(bytes);
}

void operator delete[](void* ptr)
{
	free(ptr);
}

void* operator new(Lt::usize bytes, void* ptr)
{
	return malloc(bytes);
}

void* operator new[](Lt::usize bytes, void* ptr)
{
	return malloc(bytes);
}