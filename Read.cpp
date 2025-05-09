#include "Read.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

/**
 * Constructor de la clase Read.
 * @param filename Nombre del archivo a leer.
 */
Read::Read(const std::string& filename) : filename(filename) {}

/**
 * Lee el archivo y procesa las secciones de grafo y terminales.
 * @return true si la lectura fue exitosa, false en caso contrario.
 */
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
    int totalNodes = 0;
    int totalEdges = 0;
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
            graph.addEdge(node1, node2, cost);
            graph.addEdge(node2, node1, cost);
        }
    }
    graph.setTotalNodes(totalNodes);
    graph.setTotalEdges(totalEdges);
}

void Read::processTerminalsSection(std::ifstream& file) {
    std::string line;
    int terminalRead = 0;
    int totalTerminals = 0;
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
            graph.addTerminal(terminal);
            terminalRead++;
        }
    }
    graph.setTotalTerminals(totalTerminals);

}
const ListAdy& Read::getGraph() const {
    return graph;
}