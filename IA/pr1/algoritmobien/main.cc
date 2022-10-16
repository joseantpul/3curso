#include "clasenodo.h"
#include <queue>
#include "clasesolucion.h"
#include <fstream>


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