#include "clasenodo.h"
#include <queue>

struct CompararNodos {
  bool operator()(nodo *&n1, nodo *&n2) {
    return n2->getcoste() < n1->getcoste();
  }
};

int main() {

  nodo* n = new nodo(nullptr, 1, 0);
  nodo* n2 = new nodo(n, 2, 1);
  nodo* n3 = new nodo(n2, 3, 1.2);
  nodo* n4 = new nodo(n3, 4, 3);
  nodo* n5 = new nodo(n4, 5, 8);
  nodo* n6 = new nodo(n5, 6, 1);

  std::priority_queue<nodo*, std::vector<nodo* >, CompararNodos > cola;
  cola.push(n);
  cola.push(n2);
  cola.push(n4);
  cola.push(n5);
  cola.push(n3);
  cola.push(n6);
  

  while (!cola.empty()) {
    nodo* x = cola.top();
    cola.pop();
    std::cout << x->getindice() << "-" << x->getcoste() << std::endl;
  }
  
  return 0;
}