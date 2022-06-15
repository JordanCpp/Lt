#ifndef Lt_Platforms_Windows_Core_New_hpp
#define Lt_Platforms_Windows_Core_New_hpp

#include <Lt/Core/Types.hpp>
#include <Windows.h>

class MemoryManager
{
public:
	MemoryManager();
	~MemoryManager();
	void* Allocate(Lt::usize bytes);
	void Deallocate(void* ptr);
private:
	HANDLE _Heap;
};

#endif    