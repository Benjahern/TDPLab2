#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

class ListAdy {
private:
    std::unordered_map<int, std::vector<std::pair<int, int>>> adjacencyList; // Lista de adyacencia
    std::unordered_set<int> terminals;  // Nodos terminales
    int totalNodes = 0;
    int totalEdges = 0;
    int totalTerminals = 0;
public:
    // Constructor
    ListAdy();
    

    // Método para agregar una arista
    void addEdge(int from, int to, int weight);

    // Método para agregar un nodo terminal
    void addTerminal(int terminal);

    // Método para obtener la lista de adyacencia
    const std::unordered_map<int, std::vector<std::pair<int, int>>>& getAdjacencyList() const;

    // Método para obtener los nodos terminales
    const std::unordered_set<int>& getTerminals() const;

    // Método para imprimir información del grafo
    void printGraphInfo() const;

    // Método para verificar si un nodo es terminal
    bool isTerminal(int node) const;

    // Métodos para obtener y establecer información del grafo
    int getTotalNodes() const;

    // Método para establecer el total de nodos
    void setTotalNodes(int total);

    // Método para obtener el total de aristas
    int getTotalEdges() const;

    // Método para establecer el total de aristas
    void setTotalEdges(int total);

    // Método para obtener el total de nodos terminales
    int getTotalTerminals() const;

    // Método para establecer el total de nodos terminales
    void setTotalTerminals(int total);

    // Método para obtener la lista de adyacencia de un nodo específico
    const std::vector<std::pair<int, int>>& getNeighbors(int node) const;

    // Método para obtener el peso de una arista
    int getEdgeWeight(int from, int to) const;

};
