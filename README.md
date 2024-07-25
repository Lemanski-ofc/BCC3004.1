- Observer:

Descrição:
O padrão Observer define uma dependência de um-para-muitos entre objetos, de modo que quando um objeto muda de estado, 
todos os seus dependentes são notificados e atualizados automaticamente.

Problema:
Quando temos objetos que precisam reagir a mudanças em outros objetos de forma eficiente e desacoplada, sem que o objeto 
que faz a mudança precise conhecer detalhes dos objetos dependentes.

Solução:
O padrão Observer permite que objetos (observadores) se inscrevam para receber notificações e atualizações de um objeto observável. 
Quando o objeto observável muda de estado, ele notifica todos os seus observadores automaticamente.


- Factory Methody
  Descrição:
O padrão Factory Method define uma interface para criar um objeto, mas permite que as subclasses decidam qual classe instanciar. 
Ele encapsula a criação de objetos e fornece uma maneira de delegar a lógica de instanciação para subclasses.

Problema:
Quando temos uma classe que não sabe de antemão qual objeto precisa criar, ou quando queremos delegar a responsabilidade de criação de 
objetos para subclasses.

Solução:
O Factory Method define um método que deve ser implementado pelas subclasses para criar um objeto específico. Isso permite que a lógica
de criação de objetos seja desacoplada do código cliente que usa esses objetos.

         
- Proxxy
  Descrição:
O padrão Proxy fornece um substituto ou marcador para outro objeto para controlar o acesso a ele. Ele permite que você forneça uma
 interface de substituição ou um placeholder para outro objeto.

Problema:
Quando queremos controlar o acesso a um objeto por razões como segurança, eficiência ou logging sem modificar o código do objeto 
original.

Solução:
O Proxy cria um objeto que atua como um intermediário entre o cliente e o objeto real. O Proxy recebe solicitações do cliente, 
executa a lógica adicional se necessário (como verificação de permissão, cache, etc.) e, em seguida, repassa a solicitação para o 
objeto real.
