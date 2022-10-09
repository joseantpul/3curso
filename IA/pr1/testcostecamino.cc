#include <iostream>
#include <vector>
#include <algorithm>

struct arista
{
  int nododest;
  double coste;
};

std::vector<int> hallarcamino(int nodoi, int nodof, std::vector<arista> prev) {
  float costecamino = 0;
  std::vector<int> camino;
  for(int i = nodof; i != -1; i = prev[i - 1].nododest) {
    camino.push_back(i);
    costecamino += prev[i - 1].coste;
  }

  std::reverse(camino.begin(), camino.end());
  
  if (camino[0] == nodoi)
    std::cout << costecamino << std::endl;
    return camino;
  return {};
}



int main() {

  std::vector<arista> x;
  arista dummy;
  std::cout << "nododest, coste" << std::endl;
  for(int i = 0; i < 12; i++) {
    std::cin >> dummy.nododest >> dummy.coste;
    x.push_back(dummy);
  }

  std::vector<int> c = hallarcamino(1, 12, x);
  for(int x : c) {
    std::cout << x << " ";
  }
  
  
  return 0;
}