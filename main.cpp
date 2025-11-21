#include<iostream>
#include "graph.h"

int main(int argc, char* argv[]) {

    Graph miGrafo;

    /*if (argc != 2) {
        int numVert = 0;

        std::cout << "Dame la cantidad de vertices: " << std::endl;
        std::cin >> numVert;

        if(!miGrafo.createGraph(numVert)) {
            std::cout << "No se pudo crear el grafo" << std::endl;
            return 1;
        }
    }*/

    std::cout << "Grafos" << std::endl;

    miGrafo.createGraph(3);
    miGrafo.insertEdge(1, 2);
    miGrafo.insertEdge(0, 1);
    miGrafo.insertEdge(0, 2);
    miGrafo.insertEdge(2, 1);

    miGrafo.printGraph();
    return 0;
}