#ifndef READ
#define READ

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

class Read {
private:

    std::unordered_map<int, std::vector<std::pair<int, int>>> adjacencyList; // Lista de adyacencia
    std::unordered_set<int> terminals;  // Nodos terminales
    std::string filename;               // Nombre del archivo
    
    // Métodos 
    void processGraphSection(std::ifstream& file);
    void processTerminalsSection(std::ifstream& file);
    
public:
    // Constructor
    Read(const std::string& filename);
    
    // Método principal para leer el archivo
    bool readFile();
    
    // Getters
    const std::unordered_map<int, std::vector<std::pair<int, int>>>& getAdjacencyList() const;
    const std::unordered_set<int>& getTerminals() const;
    
    // Método para imprimir información 
    void printGraphInfo() const;
    
    // Método para verificar si un nodo es terminal
    bool isTerminal(int node) const;
};

#endif