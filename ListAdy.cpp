#include "ListAdy.h"
#include <iostream>

/**
 * @brief Constructor de la clase ListAdy.
 * 
 */
ListAdy::ListAdy() {
    // Constructor
}

/**
 * @brief Añade una arista al grafo.
 * 
 * @param from inicio
 * @param to final
 * @param weight peso de la arista
 */
void ListAdy::addEdge(int from, int to, int weight) {
    adjacencyList[from].emplace_back(to, weight);
}

/**
 * @brief Añade un nodo terminal al grafo.
 
 * 
 * @param terminal nodo terminal
 */
void ListAdy::addTerminal(int terminal) {
    terminals.insert(terminal);
}
/**
 * @brief Obtiene la lista de adyacencia del grafo.
 * 
 * @return const std::unordered_map<int, std::vector<std::pair<int, int>>>& lista de adyacencia
 */
const std::unordered_map<int, std::vector<std::pair<int, int>>>& ListAdy::getAdjacencyList() const {
    return adjacencyList;
}
/**
 * @brief Obtiene los nodos terminales del grafo.
 * 
 * @return const std::unordered_set<int>& nodos terminales
 */
const std::unordered_set<int>& ListAdy::getTerminals() const {
    return terminals;
}

/**
 * @brief Imprime información del grafo.
 * 
 */
void ListAdy::printGraphInfo() const {
    std::cout << "Lista de adyacencia del grafo:" << std::endl;
    for (const auto& [node, neighbors] : adjacencyList) {
        std::cout << "Nodo " << node << " -> ";
        for (const auto& neighbor : neighbors) {
            std::cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
        }
        std::cout << std::endl;
    }
    
    std::cout << "\nNodos terminales: ";
    for (int terminal : terminals) {
        std::cout << terminal << " ";
    }
    std::cout << "\n\nTotal nodos: " << adjacencyList.size() 
              << ", Total terminales: " << terminals.size() << std::endl;
}
/**
 * @brief Verifica si un nodo es terminal.
 * 
 * @param node nodo a verificar
 * @return true si es terminal, false en caso contrario
 */
bool ListAdy::isTerminal(int node) const {
    return terminals.find(node) != terminals.end();
}

/**
 * @brief Métodos para obtener y establecer información del grafo.
 * 
 */
int ListAdy::getTotalNodes() const {
    return totalNodes;
}

/**
 * @brief Establece el total de nodos.
 * 
 * @param total total de nodos
 */
void ListAdy::setTotalNodes(int total) {
    totalNodes = total;
}

/**
 * @brief Establece el total de aristas.
 * 
 * @param total total de aristas
 */
void ListAdy::setTotalEdges(int total) {
    totalEdges = total;
}

/**
 * @brief Obtiene el total de aristas.
 * 
 * @return int total de aristas
 */
int ListAdy::getTotalEdges() const {
    return totalEdges;
}

/**
 * @brief Establece el total de nodos terminales.
 * 
 * @param total total de nodos terminales
 */
int ListAdy::getTotalTerminals() const {
    return totalTerminals;
}

/**
 * @brief Establece el total de nodos terminales.
 * 
 * @param total total de nodos terminales
 */
void ListAdy::setTotalTerminals(int total) {
    totalTerminals = total;
}

/**
 * @brief Obtiene la lista de adyacencia de un nodo específico.
 * 
 * @param node nodo a verificar
 * @return const std::vector<std::pair<int, int>>& lista de adyacencia del nodo
 */
const std::vector<std::pair<int, int>>& ListAdy::getNeighbors(int node) const {
    return adjacencyList.at(node);
}

/**
 * @brief Obtiene el peso de una arista entre dos nodos.
 * 
 * @param from nodo de inicio
 * @param to nodo final
 * @return int peso de la arista, -1 si no se encuentra
 */
int ListAdy::getEdgeWeight(int from, int to) const {
    for (const auto& neighbor : adjacencyList.at(from)) {
        if (neighbor.first == to) {
            return neighbor.second;
        }
    }
    return -1; // Retorna -1 si no se encuentra la arista
}
