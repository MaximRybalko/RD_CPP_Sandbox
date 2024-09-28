#pragma once
#include "Entity.h"
#include "Event.h"

class Observer
{
public:
	virtual ~Observer() {}
	virtual void onNotify(const Entity& entity, Event event) = 0;
	virtual int getObserverID() const = 0;
};