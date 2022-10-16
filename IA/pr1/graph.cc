#include "graph.h"
using namespace std;

Graph::Graph(std::string file) {
  std::ifstream fin;
  file = "../ejemplos/"+file;
  fin.open(file);
  fin >> nodos_;  

  // Contar numero de lineas
  int lines = 0;
  while (fin.good()) {
    if (fin.get() == '\n')
      lines++;
  }
  fin.close();
  
  // Comprobamos si el numero de lineas es correcto
  int lines_ = 0;
  for (int i = 1; i < nodos_; i++) 
    lines_ += i;
  
  if (lines != lines_)
    std::cout << "El fichero no tiene el formato adecuado." << std::endl;

  else {
    fin.open(file);
    
    costes_.resize(nodos_);
    for (int i = 0; i < costes_.size(); i++) 
      costes_[i].resize(nodos_);


    float coste;
    fin >> coste;
    for (int i = 0; i < nodos_-1; i++) {
      for (int j = i+1; j < nodos_; j++) {
        fin >> coste;
        costes_[i][j] = coste; 
        costes_[j][i] = coste; 
      }  
    }

    // Mostrar matriz de costes
    /*for (int i = 0; i < costes_.size(); i++) {
      for (int j = 0; j < costes_[i].size(); j++) {
        cout << costes_[i][j] << " ";
      }
      cout << endl;
    }*/
  }
  generados_ = 0;
  inspeccionados_ = 0;
}

void Graph::algoritmo() {
  
  int origen, destino;
  cout << "Elija el nodo origen y destino [1-" << nodos_ << "] : "; cin >> origen >> destino;
  if ( origen <= 0 || origen > nodos_ || destino <= 0 || destino > nodos_ )
    cout << "Los nodos introducidos no son válidos." << endl;
  else {
    Node* nodo = BFS(origen-1, destino-1); // Internamente c++ empieza desde 0 en vez de 1
    if (nodo->get_cost() == -1)
      cout << "No existe un camino." << endl;
    else 
      print_result(nodo);
  }
}

Node* Graph::BFS(unsigned ini, unsigned final) {
  priority_queue<Node*, vector<Node*>, decltype(cmp)> frontera(cmp);
  Node* raiz = new Node(ini, 0, NULL);
  generados_++;
  frontera.push(raiz);
  
  Node* nodo = new Node();
  while(!frontera.empty()) {
    nodo = frontera.top();
    frontera.pop();
    inspeccionados_++; // Incrementamos el contador de nodos inspeccionados
    
    if (nodo->get_id() == final) 
      return nodo;
      
    sucesores(nodo, frontera);
  }
  nodo->set_cost(-1);
  return nodo;
}


void Graph::sucesores(Node* padre, priority_queue<Node*, vector<Node*>, decltype(cmp)>& frontera) {

  for (int i = 0; i < costes_[padre->get_id()].size(); i++) {
      if (costes_[padre->get_id()][i] > 0 &&  (padre->get_padre() == NULL ? true : !visitados(padre, i))) {
        Node* nodo = new Node(i, costes_[padre->get_id()][i]+padre->get_cost(), padre);
        frontera.push(nodo);
        generados_++;
    }
  }

}

bool Graph::visitados(Node* nodo, int i) {

  while(nodo->get_padre() != NULL) {
    if(nodo->get_id() == i) 
      return true;
    nodo = nodo->get_padre();
  }
  if (nodo->get_id() == i) 
    return true;

  return false;

}

  void Graph::print_result(Node* nodo) {

    cout << "Coste: " << nodo->get_cost() << endl;
    cout << "Inspeccionados: " << inspeccionados_ << endl;
    cout << "Generados: " << generados_ << endl;
    cout << "Camino: ";

    while (nodo->get_padre() != NULL) {
      cout << nodo->get_id()+1 << " <- ";
      nodo = nodo->get_padre();
    }
    cout << nodo->get_id()+1 << endl;

  }