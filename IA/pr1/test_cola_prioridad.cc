#include <iostream>
#include <queue>
#include <vector>
#include <algorithm> //std::reverse
#include <fstream>
#include <cstdlib> //std::exit()
#include <queue>


struct enlace {
  int nododestino;
  double coste;
  friend bool operator<(const enlace& x, const enlace& y) {
    return y.coste < x.coste;
  }

};


//

int main() {

  std::priority_queue<enlace> cola;

  enlace dummy = {23, 34.32}, dummy3 = {34, 10.34}, dummy4 = {35, 56.34};
  cola.push(dummy);
  cola.push(dummy3);
  cola.push(dummy4);
  cola.push({36, 35.23});
 
  while(!cola.empty()) {
    std::cout << cola.top().coste << " ";
    cola.pop();
  }
  
  std::vector<std::vector< enlace> > matriz;
  
  

  return 0;
}