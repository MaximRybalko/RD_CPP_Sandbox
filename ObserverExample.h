#include <iostream>
#include "Observer.h"

class ObserverExample : public Observer {
public:
    ObserverExample(int id) : observerID(id) {}

    void onNotify(const Entity& entity, Event event) override {
        if (observerID == entity.getID()) {
            switch (event) {
            case Event::EVENT_A:
                std::cout << "Observer received EVENT_A from entity ID: " << entity.getID() << std::endl;
                break;
            case Event::EVENT_B:
                std::cout << "Observer received EVENT_B from entity ID: " << entity.getID() << std::endl;
                break;
            case Event::EVENT_C:
                std::cout << "Observer received EVENT_C from entity ID: " << entity.getID() << std::endl;
                break;
            default:
                std::cout << "Unknown event." << std::endl;
            }
        }
    }

    int getObserverID() const override { return observerID; }

private:
    int observerID;
};