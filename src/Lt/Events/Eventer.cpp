#include <Lt/Events/Eventer.hpp>

Lt::Events::Eventer::Eventer() :
	_Running(true)
{
}

void Lt::Events::Eventer::Push(Lt::Events::Event& event)
{
	_Queue.Enqueue(event);
}

bool Lt::Events::Eventer::Pop(Lt::Events::Event& event)
{
    if (!_Queue.IsEmpty())
    {
        _Queue.Dequeue(event);

        return true;
    }

    return false;
}

bool Lt::Events::Eventer::Running()
{
	return _Running;
}

void Lt::Events::Eventer::Stop()
{
	_Running = false;
}