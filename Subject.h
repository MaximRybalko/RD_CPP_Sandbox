#pragma once

#include <vector>
#include "Observer.h"

class Subject {
public:
    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
    void notify(const Entity& entity, Event event);

private:
    std::vector<Observer*> observers;
};