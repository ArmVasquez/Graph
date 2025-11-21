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

    miGrafo.createGraph(5);
    miGrafo.insertEdge(0, 1);
    miGrafo.insertEdge(0, 2);
    miGrafo.insertEdge(1, 0);
    miGrafo.insertEdge(1, 2);
    miGrafo.insertEdge(1, 3);
    miGrafo.insertEdge(3, 4);
    miGrafo.insertEdge(4, 2);

    miGrafo.printGraph();
    miGrafo.dfsIterative(0);
    miGrafo.bfsPath(0, 4);
    miGrafo.bfsPath(0, 0);

    return 0;
}