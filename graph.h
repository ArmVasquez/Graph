#pragma once
#include "LinkedList.h"

// Definition of the Graph class
class Graph {
public:
    Graph();
    ~Graph();

    // Methods
    bool createGraph(unsigned int vertexCount);
    bool insertEdge(int fromVertex, int toVertex);
    bool deleteEdge(int fromVertex, int toVertex);
    void deleteGraph();
    void printGraph();

    // Revisar como cargar archivo
    //loadFromFile(nombre)
    bool loadFromFile(std::string filename);
    //saveToFile(nombre)
    bool saveToFile(std::string filename);

private:
    unsigned int vertexCount;

    class Edge {
    public:
        // Constructor
        Edge(unsigned int value);

        // The destination vertex of the edge
        unsigned int destination;

        friend std::ostream& operator<<(std::ostream &os, const Edge &a);
    };

    class Vertex {
    public:
        unsigned int id;
        // A linked list to store edges
        LinkedList<Edge> edges;
    };
};