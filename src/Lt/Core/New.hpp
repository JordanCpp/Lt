#ifndef Lt_Core_New_hpp
#define Lt_Core_New_hpp

#include <Lt/Core/Types.hpp>

void* operator new(Lt::usize bytes);
void operator delete(void* ptr);

void* operator new[](Lt::usize bytes);
void operator delete[](void* ptr);

void* operator new(Lt::usize bytes, void* ptr);
void* operator new[](Lt::usize bytes, void* ptr);

#endif    