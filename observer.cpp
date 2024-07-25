/*Diagrama: 

+--------------+      notifies      +------------+
|   Subject    | -----------------> |  Observer  |
+--------------+                    +------------+
| attach(observer)                  | update()   |
| detach(observer)                  +------------+
| notifyObservers()                             |
+--------------+                               |
        |                                      |
        |                                      |
        v                                      v
+------------------+                 +------------------+
|   ConcreteSubject|                 |  ConcreteObserver |
+------------------+                 +------------------+
|    state         |                 |   state          |
+------------------+                 +------------------+
*/


//Exemplo de código

#include <iostream>
#include <vector>

// Interface Observer
class Observer {
public:
    virtual void update(int value) = 0;
};

// Concrete Observer
class ConcreteObserver : public Observer {
private:
    int observerState;

public:
    void update(int value) override {
        observerState = value;
        std::cout << "Observer state updated to: " << observerState << std::endl;
    }
};

// Subject
class Subject {
private:
    int subjectState;
    std::vector<Observer*> observers;

public:
    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    void setState(int state) {
        subjectState = state;
        notifyObservers();
    }

    void notifyObservers() {
        for (Observer* observer : observers) {
            observer->update(subjectState);
        }
    }
};

int main() {
    Subject subject;
    ConcreteObserver observer1;
    ConcreteObserver observer2;

    subject.attach(&observer1);
    subject.attach(&observer2);

    subject.setState(10);
    subject.setState(20);

    return 0;
}

