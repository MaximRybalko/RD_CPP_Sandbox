//Robot_Dreams C++ Home Work 5: Observer Pattern

#include "Subject.h"
#include "ObserverExample.h"
#include "Entity.h"
#include "Event.h"

int main() {
    
        Subject subject;
        ObserverExample observer1(1);
        ObserverExample observer2(2);
        ObserverExample observer3(3);

        Entity entity1(1);
        Entity entity2(2);
        Entity entity3(3);

        subject.addObserver(&observer1);
        subject.addObserver(&observer2);
        subject.addObserver(&observer3);

        subject.notify(entity1, Event::EVENT_A);
        subject.notify(entity2, Event::EVENT_B);
        subject.notify(entity3, Event::EVENT_C);

        subject.removeObserver(&observer1);
        subject.removeObserver(&observer2);
        subject.removeObserver(&observer3);

        return 0;
    
}
