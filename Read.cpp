#include "Read.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

Read::Read(const std::string& filename) : filename(filename) {}

bool Read::readFile() {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error al abrir el archivo: " << filename << std::endl;
        return false;
    }
    
    std::string line;
    while (getline(file, line)) {
        // Ignorar líneas vacías y comentarios
        if (line.empty() || line.find("Comment") != std::string::npos) {
            continue;
        }
        
        // Buscar secciones importantes
        if (line.find("SECTION Graph") != std::string::npos) {
            processGraphSection(file);
        } else if (line.find("SECTION Terminals") != std::string::npos) {
            processTerminalsSection(file);
        }
        
        // Terminar si encontramos EOF
        if (line.find("EOF") != std::string::npos) {
            break;
        }
    }
    
    file.close();
    return true;
}

void Read::processGraphSection(std::ifstream& file) {
    std::string line;
    int edgeRead = 0;
    while (getline(file, line)) {
        // Terminar si encontramos el fin de la sección
        if (line.find("END") != std::string::npos) {
            break;
        }
        // Leer cantidad de nodos y aristas
        if (line.find("Nodes") != std::string::npos) {
            std::istringstream iss(line);
            std::string trash;
            iss >> trash >> totalNodes;
        } 

        else if (line.find("Edges") != std::string::npos) {
            std::istringstream iss(line);
            std::string trash;
            iss >> trash >> totalEdges;
        }

        
        // Procesar línea de arista
        else if (line[0] == 'E' && edgeRead < totalEdges) {
            std::istringstream iss(line);
            char e;
            int node1, node2, cost;
            iss >> e >> node1 >> node2 >> cost;
            
            // Añadir a la lista de adyacencia (grafo no dirigido)
            adjacencyList[node1].emplace_back(node2, cost);
            adjacencyList[node2].emplace_back(node1, cost);
            edgeRead++;
        }
    }
}

void Read::processTerminalsSection(std::ifstream& file) {
    std::string line;
    int terminalRead = 0;
    while (getline(file, line)) {
        // Terminar si encontramos el fin de la sección
        if (line.find("END") != std::string::npos) {
            break;
        }
        // Leer cantidad de terminales
        if (line.find("Terminals") != std::string::npos) {
            std::istringstream iss(line);
            std::string trash;
            iss >> trash >> totalTerminals;
        }
        
        // Procesar línea de terminal
        if (line[0] == 'T' && terminalRead < totalTerminals) {
            std::istringstream iss(line);
            char t;
            int terminal;
            iss >> t >> terminal;
            terminals.insert(terminal);
            terminalRead++;
        }
    }
}

const std::unordered_map<int, std::vector<std::pair<int, int>>>& Read::getAdjacencyList() const {
    return adjacencyList;
}

const std::unordered_set<int>& Read::getTerminals() const {
    return terminals;
}

bool Read::isTerminal(int node) const {
    return terminals.find(node) != terminals.end();
}
int Read::getTotalNodes() const {
    return totalNodes;
}
int Read::getTotalEdges() const {
    return totalEdges;
}
int Read::getTotalTerminals() const {
    return totalTerminals;
}

void Read::printGraphInfo() const {
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