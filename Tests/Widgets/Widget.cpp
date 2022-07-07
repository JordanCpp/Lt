#include <Lt/Core/TestEqual.hpp>
#include <Lt/Widgets/Factory.hpp>

void Click(Lt::Widgets::Widget* source, Lt::usize type, void* content)
{
	LT_TEST_EQUAL(source != nullptr);
	LT_TEST_EQUAL(type > 0);
	LT_TEST_EQUAL(content != nullptr);
}

void TestWidgetsWidget()
{
	Lt::Core::ErrorHandler errorHandler;

	Lt::Graphics::Window window(errorHandler, Lt::Graphics::Point2u(0, 0), Lt::Graphics::Point2u(800, 600), "Window!");

	Lt::Graphics::Render render(errorHandler, &window);

	Lt::Widgets::Factory factory(&window, &render);

	Lt::Widgets::Widget* widget = factory.Button(Lt::Graphics::Point2u(10, 15), Lt::Graphics::Point2u(100, 25));

	LT_TEST_EQUAL(widget->Action() == nullptr);
	LT_TEST_EQUAL(widget->Parent() == nullptr);

	LT_TEST_EQUAL(widget->Pos().PosX() == 10);
	LT_TEST_EQUAL(widget->Pos().PosY() == 15);

	LT_TEST_EQUAL(widget->Size().PosX() == 100);
	LT_TEST_EQUAL(widget->Size().PosY() == 25);

	LT_TEST_EQUAL(widget->Window() == &window);
	LT_TEST_EQUAL(widget->Render() == &render);

	widget->Action(Click);

	LT_TEST_EQUAL(widget->Action() == Click);

	widget->Action(widget, 1, (void*)42);
}

int main()
{
	TestWidgetsWidget();

	return 0;
}