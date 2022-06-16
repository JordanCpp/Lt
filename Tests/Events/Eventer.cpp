#include <Lt/Core/TestEqual.hpp>
#include <Lt/Events/Eventer.hpp>

void TestEventsEventer()
{
	Lt::Events::Eventer eventer;

	LT_TEST_EQUAL(eventer.Max == 128);
	LT_TEST_EQUAL(eventer.Running() == true);

	Lt::Events::Event event;
	event.Type = Lt::Events::IsQuit;
	eventer.Push(event);
	LT_TEST_EQUAL(eventer.Running() == true);

	Lt::Events::Event dest;
	LT_TEST_EQUAL(eventer.Pop(dest) == true);
	LT_TEST_EQUAL(dest.Type == Lt::Events::IsQuit);
	LT_TEST_EQUAL(eventer.Running() == true);

	eventer.Stop();
	LT_TEST_EQUAL(eventer.Running() == false);
}

int main()
{
	TestEventsEventer();

	return 0;
}