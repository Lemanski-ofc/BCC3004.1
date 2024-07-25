/*Diagrama:
                   +------------------+
                  |     Creator      |
                  +------------------+
                  | +FactoryMethod() |
                  +------------------+
                          |
                          |
                   +------+------+
                   |             |
         +---------+--+    +-----+---------+
         |  ConcreteCreator1  |  ConcreteCreator2 |
         +--------------------+------------------+
         | +FactoryMethod()   | +FactoryMethod() |
         +--------------------+------------------+
*/

//Código:

#include <iostream>

// Product
class Product {
public:
    virtual void use() = 0;
};

// Concrete Product A
class ConcreteProductA : public Product {
public:
    void use() override {
        std::cout << "Using Product A" << std::endl;
    }
};

// Concrete Product B
class ConcreteProductB : public Product {
public:
    void use() override {
        std::cout << "Using Product B" << std::endl;
    }
};

// Creator
class Creator {
public:
    virtual Product* factoryMethod() = 0;

    void operation() {
        Product* product = factoryMethod();
        product->use();
    }
};

// Concrete Creator A
class ConcreteCreatorA : public Creator {
public:
    Product* factoryMethod() override {
        return new ConcreteProductA();
    }
};

// Concrete Creator B
class ConcreteCreatorB : public Creator {
public:
    Product* factoryMethod() override {
        return new ConcreteProductB();
    }
};

int main() {
    Creator* creatorA = new ConcreteCreatorA();
    Creator* creatorB = new ConcreteCreatorB();

    creatorA->operation();
    creatorB->operation();

    delete creatorA;
    delete creatorB;

    return 0;
}
