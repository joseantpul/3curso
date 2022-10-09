#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib> //exit

struct arista
{
    int ndestino;
    double coste;
};

std::vector<std::vector<arista> > creargrafo() {
  std::vector<std::vector<arista> > grafo;
  int nnodos, pivote, comienzo, hastannodos, resta;
  double coste;
  std::string filename;

  std::cout << "Introduce el nombre del fichero " << std::endl;
  std::cin >> filename;

  std::ifstream myfile (filename); 

  if (myfile.is_open()) {
    myfile >> nnodos;

    if(nnodos > 1) comienzo = 2;
    else comienzo = 1;

    grafo.resize(nnodos, {});

    resta = nnodos - 1;
    pivote = 1;

    arista dummy, dummy2;

    while (resta > 0) {

      std::cout << "aristas para el nodo " << pivote << std::endl;
      hastannodos = comienzo;

      for(int i = 0; i < resta; i++) {

        myfile >> coste;
        dummy = {hastannodos, coste};
        std::cout << dummy.ndestino << " " << dummy.coste << std::endl;
        
        if(coste != -1) {
          grafo[pivote - 1].push_back(dummy);
          dummy2 = {pivote, dummy.coste};
          grafo[dummy.ndestino - 1].push_back(dummy2);
        }

        hastannodos++;
      }

      std::cout << std::endl;
      resta--;
      pivote++;
      comienzo++;
    }
    
  }
  else {
    std::cout << "error fichero no existe" << std::endl;
    std::exit(EXIT_FAILURE);
  }

  std::cout << "El número de nodos es " << nnodos << std::endl << std::endl << "Lista de adyacencia: " << std::endl;

  for(auto x : grafo) {
    for(arista y: x) {
      std::cout << y.ndestino << " " << y.coste << "|";
    }
    std::cout << std::endl;
  }

  return grafo;
  
}



int main() {

  creargrafo();  

  return 0;

}