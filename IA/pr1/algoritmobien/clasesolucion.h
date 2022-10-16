#include <iostream>
#include <queue>
#include <vector>
#include <algorithm> //std::reverse
#include <fstream>
#include <cstdlib> //std::exit()
#include "clasenodo.h"


struct arista {
  int nododestino;
  double coste;
  friend bool operator<(const arista& x, const arista& y) {
    return y.coste < x.coste;
  }
};


class maquinadebusquedas{
 public:
  maquinadebusquedas() {}
  void creargrafo();
  void pediriniciales();
  void costouniforme();
  void mostrarcamino();

 private:
  int nodosgenerados;
  int nodosvisitados;
  int nvertices;
  int naristas;
  int nodoi;
  int nodof;
  int nnodos;
  std::vector<std::vector<arista> > grafo;
  nodo* nodofinalbusqueda; //nodo final de la búsqueda, desde el se hace el recorrido hacia atrás

};
/*
void maquinadebusquedas::creargrafo() {
  int pivote, comienzo, hastannodos, resta;
  double coste;
  std::string filename;

  std::cout << "Introduce el nombre del fichero " << std::endl;
  std::cin >> filename;

  std::ifstream myfile (filename); 

  if (myfile.is_open()) {
    myfile >> this->nnodos;

    if(nnodos > 1) comienzo = 2;
    else comienzo = 1;

    this->grafo.resize(nnodos, {});

    resta = nnodos - 1;
    pivote = 1;

    arista dummy, dummy2;

    while (resta > 0) {

      //std::cout << "aristas para el nodo " << pivote << std::endl;
      hastannodos = comienzo;

      for(int i = 0; i < resta; i++) {

        myfile >> coste;
        dummy = {hastannodos, coste};
        //std::cout << dummy.nododestino << " " << dummy.coste << std::endl;
        
        if(coste != -1) {
          this->grafo[pivote - 1].push_back(dummy);
          dummy2 = {pivote, dummy.coste};
          this->grafo[dummy.nododestino - 1].push_back(dummy2);
        }

        hastannodos++;
      }

      //std::cout << std::endl;
      resta--;
      pivote++;
      comienzo++;
    }
    
  }
  else {
    std::cout << "error fichero no existe" << std::endl;
    std::exit(EXIT_FAILURE);
  }

}

void maquinadebusquedas::pediriniciales() {
  
    std::cout << "Escribe el nodo inicial de la búsqueda: "; std::cin >> nodoi;
    std::cout << "Escribe el nodo final de la búsqueda: "; std::cin >> nodof;

}

void maquinadebusquedas::costouniforme() {
  std::vector<bool> visitados;
  visitados.resize(nnodos, 0);
  
  std::priority_queue<nodo* > cola;
  cola.push(new nodo(nullptr, nodoi, 0));
  
  std::vector<arista> vecinos;
  nodo* nactual = nullptr;
  double costecamino;
  nodo* indice = nullptr; //nodo para recorrer el árbol hacia atrás y ver los visitados del camino
  while(!cola.empty()) {

    visitados[nodoi - 1] = true; //el nodo inicial siempre está en el camino

    nactual = cola.top();
    cola.pop();

    std::cout << "visitando nodo " <<  nactual->getindice() << std::endl;

    if(nactual->getindice() == this->nodof) {
      nodofinalbusqueda = nactual;
      return;
    }
    
    vecinos = grafo[nactual->getindice() - 1];
    indice = nactual;
    while(indice->getindice() != nodoi) {
      visitados[indice->getindice() - 1] = true;
      indice = indice->getpadre();
    }

    costecamino = nactual->getcoste();

    for(arista vecino : vecinos) {
      if(!visitados[vecino.nododestino - 1]) { //que no se haya visitado en el camino
        cola.push(new nodo(nactual, vecino.nododestino, vecino.coste + costecamino));
      }
    }
    visitados.clear();
    visitados.resize(nnodos, 0);
  }

  return;  //esto esta mal falta algo
}

void maquinadebusquedas::mostrarcamino() {

  std::cout << "Camino al reves con coste " << nodofinalbusqueda->getcoste() << std::endl;
  while(true) {
    std::cout << nodofinalbusqueda->getindice() << " ";
    if(nodofinalbusqueda->getpadre() == nullptr) break;
    nodofinalbusqueda = nodofinalbusqueda->getpadre();
  }

  

}

*/