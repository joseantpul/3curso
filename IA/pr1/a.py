import matplotlib.pyplot as plt
import networkx as nx
import sys

# Comprobamos argumentos
if len(sys.argv) < 2:
    print("Usage: ./visualizarDebug.py <archivo>")
    sys.exit(1)

# Leemos la matriz del archivo
with open(sys.argv[1], "r") as f:
    n = int(f.readline())
    matriz = [[-1.0 for i in range(n)] for j in range(n)]
    for i in range(n):
        for j in range(i+1, n):
            matriz[i][j] = float(f.readline())
            matriz[j][i] = matriz[i][j]

# generamos el grafo a partir de la matriz
G = nx.Graph()

for i in range(n):
    G.add_node(i + 1, color="green")

for i in range(n):
    for j in range(i+1, n):
        if matriz[i][j] != -1:
            G.add_edge(i + 1, j + 1, weight=matriz[i][j])

# Dibujamos el grafo
pos = nx.spring_layout(G)
colors = [node[1]['color'] for node in G.nodes(data=True)]
weights = nx.get_edge_attributes(G, 'weight').values()
weights = [w/max(weights) for w in weights]  # Normalizamos
nx.draw(G, pos=pos, node_color=colors, with_labels=True, width=list(weights))
plt.show()