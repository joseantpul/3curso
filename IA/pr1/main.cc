
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm> //std::reverse
#include <fstream>
#include <cstdlib> //std::exit()


//grafo de wikipedia camino minimo entre 1 y 11 es [1, 4, 7, 11]

struct arista {
 int nododestino;
 double coste;
};

int kNnodos;

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
    kNnodos = nnodos;
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
        std::cout << dummy.nododestino << " " << dummy.coste << std::endl;
        
        if(coste != -1) {
          grafo[pivote - 1].push_back(dummy);
          dummy2 = {pivote, dummy.coste};
          grafo[dummy.nododestino - 1].push_back(dummy2);
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
      std::cout << y.nododestino << " " << y.coste << "|";
    }
    std::cout << std::endl;
  }

  return grafo;
  
}

//HAY QUE COMPROBAR QUE ESTO FUNCIONA PERO PRIMERO TENGO QUE HACER PARA LEER FICHERO Y OBTENER EL grafo
std::vector<arista> previo(std::vector< std::vector<arista> > grafo, int nodoi, int numnodos) {
  std::queue<int> cola;
  cola.push(nodoi);

  std::vector<arista> prev;
  //prev.resize(numnodos, -1);
  arista dummy = {-1 , 0};
  for(int i = 0; i < numnodos; i++)  {
    prev.push_back(dummy);
  }


  std::vector<bool> visitados;
  visitados.resize(numnodos, false);
  visitados[nodoi - 1] = true;

  int nodovisitado;
  std::vector<arista> vecinos;
  while (!cola.empty()) {
    vecinos.erase(vecinos.begin(), vecinos.end());
    nodovisitado = cola.front();
    cola.pop();

    vecinos = grafo[nodovisitado - 1];

    for(arista n : vecinos) {
      if( !visitados[n.nododestino - 1] ) {
        cola.push(n.nododestino);
        visitados[n.nododestino - 1] = true;
        prev[n.nododestino - 1].nododestino = nodovisitado;
        prev[n.nododestino - 1].coste = n.coste;
      }
    }

  }
  
  return prev;
}

std::vector<int> hallarcamino(int nodoi, int nodof, std::vector<arista> prev) {
  float costecamino = 0;
  std::vector<int> camino;
  for(int i = nodof; i != -1; i = prev[i - 1].nododestino) {
    camino.push_back(i);
    costecamino += prev[i - 1].coste;
  }

  std::reverse(camino.begin(), camino.end());
  
  if (camino[0] == nodoi)
    std::cout << "El coste del camino es: " << costecamino << std::endl;
    return camino;
  return {};
}

/*
COSAS QUE SE ME VAN OCURRIENDO:
-SI EL GRAFO NO EMPIEZA EN 1 HACER UNA MATRIZ A SECAS NO FUNCIONA
CASI RESUELTO (PREGUNTAR SI NOS VAN A PEDIR NODO PRIMERO = 1): POR LA FORMA EN LA QUE ESTA HECHA EL FICHERO NO HACE FALTA (CREO PORQ SI EN CLASE ME DICEN EMPIEZA EN 0 SIGUE ESTANDO MAL)
-¿HACER CLASE GRAFO (CREO QUE ESTARIA BIEN)?
*/

int main() {

  std::vector< std::vector<arista> > graph = creargrafo();

  int ninicial, nfinal;
  std::cout << "Escribe el nodo inicial de la búsqueda: "; std::cin >> ninicial;
  std::cout << "Escribe el nodo final de la búsqueda: "; std::cin >> nfinal;

  std::vector<arista> x = previo(graph, ninicial, kNnodos);
  std::vector<int> camino = hallarcamino(ninicial, nfinal, x);

  std::cout << "El camino es: ";
  for(int i : camino) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  return 0;
}