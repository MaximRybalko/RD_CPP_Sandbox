#include <iostream>
#include "Subject.h"

void Subject::addObserver(Observer* observer) {
    observers.push_back(observer);
}

void Subject::removeObserver(Observer* observer) {
    int observerID = observer->getObserverID();
    
    observers.erase(
        std::remove(observers.begin(), observers.end(), observer),
        observers.end()        
    );

    std::cout << "Observer " << observerID << " removed.\n";
    
}

void Subject::notify(const Entity& entity, Event event) {
    for (Observer* observer : observers) {
        observer->onNotify(entity, event);
    }
}
