#ifndef NODO
#define NODO

#include <iostream>
#include <vector>



class nodo {
 public:
  nodo() {};
  nodo(nodo* p, int ind, double cost) {padre = p; indice = ind; coste = cost;}
  nodo* getpadre() {return padre;}
  int getindice() {return indice;}
  double getcoste() {return coste;}

 private: 
  nodo* padre;
  int indice;
  double coste;
};



#endif