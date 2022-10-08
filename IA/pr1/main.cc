
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm> //std::reverse


//grafo de wikipedia camino minimo entre 1 y 11 es [1, 4, 7, 11]

std::vector<int> previo(std::vector< std::vector<int> > grafo, int nodoi, int numnodos) {
  std::queue<int> cola;
  cola.push(nodoi);

  std::vector<int> prev;
  prev.resize(numnodos, -1);

  std::vector<bool> visitados;
  visitados.resize(numnodos, false);
  visitados[nodoi - 1] = true;

  int nodovisitado;
  std::vector<int> vecinos;
  while (!cola.empty()) {
    nodovisitado = cola.front();
    cola.pop();

    vecinos = grafo[nodovisitado - 1];
    
    for(int n : vecinos) {
      if( !visitados[n - 1] ) {
        cola.push(n);
        visitados[n - 1] = true;
        prev[n - 1] = nodovisitado;
      }
    }

  }
  
  return prev;
}

std::vector<int> hallarcamino(int nodoi, int nodof, std::vector<int> prev) {
  std::vector<int> camino;
  for(int i = nodof; i != -1; i = prev[i - 1]) {
    camino.push_back(i);
  }

  std::reverse(camino.begin(), camino.end());
  
  if (camino[0] == nodoi)
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

  std::vector< std::vector<int> > graph;
  graph = {
    {2, 3, 4}, //1
    {5, 6}, //2
    {}, //3
    {7, 8}, //4
    {9, 10}, //5
    {},  //6
    {11, 12}, //7
    {}, {}, {}, {}, {}  //8
  };

  std::vector<int> x = previo(graph, 1, 12);
  x = hallarcamino(1, 11, x);
  for(int i : x) {
    std::cout << i << " ";
  }
  return 0;
}