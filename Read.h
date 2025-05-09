#ifndef READ
#define READ

#include <vector>
#include "ListAdy.h"
#include <string>
#include <unordered_set>
#include <unordered_map>

class Read {
private:

    std::string filename;               // Nombre del archivo
    ListAdy graph;          // Lista de adyacencia
    
    void processGraphSection(std::ifstream& file);
    void processTerminalsSection(std::ifstream& file);
    
public:
    // Constructor
    Read(const std::string& filename);
    
    // Método principal para leer el archivo
    bool readFile();
    // Métodos para obtener información del grafo
    const ListAdy& getGraph() const;
};

#endif