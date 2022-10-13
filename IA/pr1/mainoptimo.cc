
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm> //std::reverse
#include <fstream>
#include <cstdlib> //std::exit()


double INFINITO = 10000000;

//grafo de wikipedia camino minimo entre 1 y 11 es [1, 4, 7, 11]

struct arista {
  int nododestino;
  double coste;
  friend bool operator<(const arista& x, const arista& y) {
    return y.coste < x.coste;
  }
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
std::vector<arista> previo(std::vector< std::vector<arista> > grafo, int nodoi, int nfinal, int numnodos) {
  
  

  std::vector<arista> previoycost;
  previoycost.resize(numnodos, {-1, INFINITO});
  std::vector<bool> visitados;
  visitados.resize(numnodos, 0);
  
  std::priority_queue<arista> cola;
  cola.push({nodoi, 0});
  previoycost[nodoi - 1].coste = 0;
  
  std::vector<arista> vecinos;
  arista nactual;
  double costecamino;
  while(!cola.empty()) {
    
    nactual = cola.top();
    cola.pop();

    std::cout << "visitando nodo " <<  nactual.nododestino << std::endl;

    if(nactual.nododestino == nfinal) return previoycost;
    
    vecinos = grafo[nactual.nododestino - 1];
    for(int i = nactual.nododestino; i != -1; i = previoycost[i - 1].nododestino) {
      visitados[i - 1] = true; 
    }

    costecamino = previoycost[nactual.nododestino - 1].coste;

    for(arista vecino : vecinos) {
      if(!visitados[vecino.nododestino - 1]) { //que no se haya visitado en el camino
        cola.push({vecino.nododestino, vecino.coste + costecamino});
        if(previoycost[vecino.nododestino - 1].coste > vecino.coste) {  //meter en prev solo el de menor coste
          previoycost[vecino.nododestino - 1] = {nactual.nododestino, costecamino + vecino.coste};
        }
      }

    }

    visitados.resize(numnodos, 0);
  }

  return previoycost;

}





/*
COSAS QUE SE ME VAN OCURRIENDO:
-SI EL GRAFO NO EMPIEZA EN 1 HACER UNA MATRIZ A SECAS NO FUNCIONA
CASI RESUELTO (PREGUNTAR SI NOS VAN A PEDIR NODO PRIMERO = 1): POR LA FORMA EN LA QUE ESTA HECHA EL FICHERO NO HACE FALTA (CREO PORQ SI EN CLASE ME DICEN EMPIEZA EN 0 SIGUE ESTANDO MAL)
-¿HACER CLASE GRAFO (CREO QUE ESTARIA BIEN)?
*/

int main() {
  std::cout << "Programa de busqueda del camino entre dos grafos" << std::endl;
  int opcion = -1, instacia = 1;
  std::ofstream ficherosalida("salida.txt");
  //ficherosalida << "Instancia |  n  |  m  |  v0  |  v1  |  Camino  |  Distancia  |  Nodos generados  |  Nodos inspeccionados  |\n";
  while(opcion != 0) {

    std::vector< std::vector<arista> > graph = creargrafo();

    int ninicial, nfinal;
    std::cout << "Escribe el nodo inicial de la búsqueda: "; std::cin >> ninicial;
    std::cout << "Escribe el nodo final de la búsqueda: "; std::cin >> nfinal;

    std::vector<arista> pr = previo(graph, ninicial, nfinal, kNnodos);
    std::cout << "predecesores" << std::endl;

    
    for(arista x : pr) {
      std::cout << x.nododestino << "," << x.coste <<" - ";
    }
    std::cout << std::endl;

    std::cout << "camino (al reves) con coste " << pr[nfinal - 1].coste << std::endl;
    for(int i = nfinal; i != -1; i = pr[i - 1].nododestino) {
      std::cout << i << " ";
    }
    std::cout << std::endl;



    std::cout << "Si quieres salir del programa escribe 0, si no escribe 1... "; std::cin >> opcion;
    instacia++;
    
  }
  std::cout << "saliendo..." << std::endl;
  ficherosalida.close();
  return 0;
}