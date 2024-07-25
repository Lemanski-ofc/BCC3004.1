
Diagrama:
                  +--------------+
                  |    Subject   |
                  +--------------+
                  | +Request()   |
                  +--------------+
                          |
                          |
                   +------+------+
                   |             |
          +--------+---+     +---+---------+
          |  Proxy    |     |   RealSubject |
          +-----------+     +--------------+
          | +Request()|     | +Request()   |
          +-----------+     +--------------+
*/

//Código:
#include <iostream>

// Subject
class Subject {
public:
    virtual void request() = 0;
};

// Real Subject
class RealSubject : public Subject {
public:
    void request() override {
        std::cout << "RealSubject: Handling request." << std::endl;
    }
};

// Proxy
class Proxy : public Subject {
private:
    RealSubject* realSubject;

    void lazyInitialization() {
        if (!realSubject) {
            realSubject = new RealSubject();
        }
    }

public:
    Proxy() : realSubject(nullptr) {}

    void request() override {
        lazyInitialization();
        std::cout << "Proxy: Checking access prior to firing a real request." << std::endl;
        realSubject->request();
    }
};

int main() {
    Proxy proxy;
    proxy.request();

    return 0;
