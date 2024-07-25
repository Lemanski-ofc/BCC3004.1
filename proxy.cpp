/*Descrição:
O padrão Proxy fornece um substituto ou marcador para outro objeto para controlar o acesso a ele. Ele permite que você forneça uma
 interface de substituição ou um placeholder para outro objeto.

Problema:
Quando queremos controlar o acesso a um objeto por razões como segurança, eficiência ou logging sem modificar o código do objeto 
original.

Solução:
O Proxy cria um objeto que atua como um intermediário entre o cliente e o objeto real. O Proxy recebe solicitações do cliente, 
executa a lógica adicional se necessário (como verificação de permissão, cache, etc.) e, em seguida, repassa a solicitação para o 
objeto real.

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
