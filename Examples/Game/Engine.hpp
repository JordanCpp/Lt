#ifndef Lt_Game_Engine_hpp
#define Lt_Game_Engine_hpp

#include <Lt/Graphics/Render.hpp>
#include <Lt/Graphics/FpsCounter.hpp>
#include <Lt/Core/IntegerToString.hpp>

class Engine
{
public:
	Engine(const Lt::Graphics::Point2u size);
	void Run();
	void CalcFps();
private:
	Lt::Core::ErrorHandler _ErrorHandler;
	Lt::Graphics::Window _Window;
	Lt::Graphics::Render _Render;
	Lt::Graphics::FpsCounter _FpsCounter;
	Lt::Core::IntegerToString _IntegerToString;
};

#endif    