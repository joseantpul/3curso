#include "clasenodo.h"
#include <queue>
#include "clasesolucion.h"
#include <fstream>

/*void previo(std::vector< std::vector<arista> > grafo, int nodoi, int nfinal, int numnodos) {
  
  std::vector<bool> visitados;
  visitados.resize(numnodos, 0);
  
  std::priority_queue<nodo* > cola;
  cola.push(new nodo(nullptr, nodoi, 0));
  
  std::vector<arista> vecinos;
  nodo* nactual = nullptr;
  double costecamino;
  while(!cola.empty()) {
    
    nactual = cola.top();
    cola.pop();

    std::cout << "visitando nodo " <<  nactual.nododestino << std::endl;

    if(nactual.nododestino == nfinal) {
      return ;
    }
    
    vecinos = grafo[nactual.nododestino - 1];
    for(int i = nactual.nododestino; i != -1; i = previoycost[i - 1].nododestino) {
      visitados[i - 1] = true; 
    }

    costecamino = previoycost[nactual.nododestino - 1].coste;

    for(arista vecino : vecinos) {
      if(!visitados[vecino.nododestino - 1]) { //que no se haya visitado en el camino
        cola.push({vecino.nododestino, vecino.coste + costecamino});
        if(previoycost[vecino.nododestino - 1].coste > vecino.coste + costecamino) {  //meter en prev solo el de menor coste
          previoycost[vecino.nododestino - 1] = {nactual.nododestino, costecamino + vecino.coste};
        }
      }
      
    }
    visitados.clear();
    visitados.resize(numnodos, 0);
  }

  return  //esto esta mal falta algo

}
*/


int main() {
  maquinadebusquedas maquina;
  int opcion = 0;
  while(opcion < 2) {
    if(opcion == 0) {
      maquina.creargrafo();
    }
    maquina.pediriniciales();

    maquina.costouniforme();
    maquina.mostrarcamino();

    std::cout << "Introduce (0) Para crear un grafo distinto (1) Para usar el mismo grafo (2) Para salir" << std::endl;
    std::cin >> opcion;
  }

  return 0;
}