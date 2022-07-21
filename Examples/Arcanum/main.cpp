#include "Engine.hpp"

int main()
{
	Arcanum::Engine engine(Lt::Graphics::Point2u(800, 600));
	engine.Run();

	return 0;
}