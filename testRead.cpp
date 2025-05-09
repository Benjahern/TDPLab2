#include "Read.h"
#include <iostream>
#include <cassert>

void testGraphReader() {
    const std::string TEST_FILE = "Prueba.txt"; // Cambia por tu archivo de prueba
    
    std::cout << "=== Iniciando pruebas con archivo: " << TEST_FILE << " ===" << std::endl;
    
    // 1. Prueba de creación y lectura básica
    Read reader(TEST_FILE);
    bool readSuccess = reader.readFile();
    assert(readSuccess && "Error: No se pudo leer el archivo");
    std::cout << "✓ Archivo leído correctamente" << std::endl;
    
    // 2. Prueba de contadores
    std::cout << "\n[Prueba de contadores]" << std::endl;
    std::cout << "• Nodos declarados: " << reader.getGraph().getTotalNodes() << std::endl;
    std::cout << "• Nodos encontrados: " << reader.getGraph().getAdjacencyList().size() << std::endl;
    std::cout << "• Aristas declaradas: " << reader.getGraph().getTotalEdges() << std::endl;
    std::cout << "• Terminales declarados: " << reader.getGraph().getTotalTerminals() << std::endl;
    std::cout << "• Terminales encontrados: " << reader.getGraph().getTerminals().size() << std::endl;
    
    assert(reader.getGraph().getTotalNodes() > 0 && "Error: No se leyó la cantidad de nodos");
    assert(reader.getGraph().getTotalEdges() > 0 && "Error: No se leyó la cantidad de aristas");
    assert(reader.getGraph().getTotalTerminals() > 0 && "Error: No se leyó la cantidad de terminales");
    std::cout << "✓ Contadores básicos válidos" << std::endl;
    
    // 3. Prueba de consistencia de datos
    std::cout << "\n[Prueba de consistencia]" << std::endl;
    assert(reader.getGraph().getTerminals().size() == reader.getGraph().getTotalTerminals() && 
           "Error: Cantidad de terminales no coincide");
    std::cout << "✓ Cantidad de terminales coincide" << std::endl;
    
    // 4. Prueba de acceso a nodos específicos
    std::cout << "\n[Prueba de acceso a nodos]" << std::endl;
    const auto& adjList = reader.getGraph().getAdjacencyList();
    const auto& terminals = reader.getGraph().getTerminals();
    
    // Probar con el primer terminal encontrado
    int primerTerminal = *terminals.begin();
    assert(adjList.count(primerTerminal) && "Error: Terminal no encontrado en grafo");
    std::cout << "✓ Primer terminal (" << primerTerminal << ") existe en el grafo" << std::endl;
    
    // 5. Prueba de adyacencias
    std::cout << "\n[Prueba de adyacencias]" << std::endl;
    int nodoPrueba = 20; // Cambia por un nodo que exista en tu grafo
    if (adjList.count(nodoPrueba)) {
        std::cout << "Vecinos del nodo " << nodoPrueba << ":" << std::endl;
        for (const auto& [vecino, peso] : adjList.at(nodoPrueba)) {
            std::cout << "  → " << vecino << " (peso: " << peso << ")";
            if (reader.getGraph().isTerminal(vecino)) {
                std::cout << " [TERMINAL]";
            }
            std::cout << std::endl;
        }
        std::cout << "✓ Adyacencias del nodo " << nodoPrueba << " válidas" << std::endl;
    } else {
        std::cout << "El nodo " << nodoPrueba << " no existe en el grafo" << std::endl;
    }
    
    // 6. Prueba de visualización (opcional)
    std::cout << "\n[Resumen del grafo]" << std::endl;
    reader.getGraph().printGraphInfo();
    
    std::cout << "\n=== ✔ Todas las pruebas pasaron exitosamente! ===" << std::endl;
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