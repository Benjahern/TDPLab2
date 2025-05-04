#include "Read.h"
#include <iostream>
#include <cassert>

void testGraphReader() {
    // Cambia esta ruta por la ubicación de tu archivo de prueba
    
    std::cout << "Iniciando pruebas " << std::endl;
    
    // 1. Prueba de lectura básica
    Read reader("Prueba.txt");
    bool readSuccess = reader.readFile();
    assert(readSuccess && "Error: No se pudo leer el archivo");
    std::cout << "✓ Archivo leído correctamente" << std::endl;
    
    // 2. Prueba de estructura del grafo
    const auto& adjList = reader.getAdjacencyList();
    assert(!adjList.empty() && "Error: Lista de adyacencia vacía");
    std::cout << "✓ Lista de adyacencia contiene " << adjList.size() << " nodos" << std::endl;
    
    // 3. Prueba de terminales
    const auto& terminals = reader.getTerminals();
    assert(!terminals.empty() && "Error: No se encontraron terminales");
    std::cout << "✓ Conjunto de terminales contiene " << terminals.size() << " nodos" << std::endl;
    
    // 4. Prueba de acceso a vecinos
    for (const auto& terminal : terminals) {
        assert(adjList.count(terminal) && "Error: Terminal no encontrado en la lista de adyacencia");
        std::cout << "  Terminal " << terminal << " tiene " 
                  << adjList.at(terminal).size() << " conexiones" << std::endl;
    }
    
    // 5. Prueba de visualización (opcional)
    std::cout << "\nResumen del grafo:" << std::endl;
    reader.printGraphInfo();
    
    std::cout << "\n✔ Todas las pruebas pasaron exitosamente!\n";
    //std::cout << adjList.at(7)[0].first << std::endl; para mostrar el primer vecino del nodo 7
}

int main() {
    try {
        testGraphReader();
    } catch (const std::exception& e) {
        std::cerr << "✖ Error en las pruebas: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}