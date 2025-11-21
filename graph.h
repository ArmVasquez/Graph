#pragma once

#include "LinkedList.h"

// Definition of the Graph class
class Graph {
public:
    Graph();
    ~Graph();

    // Methods
    bool createGraph(unsigned int vertexCount);
    bool insertEdge(unsigned int fromVertex, unsigned int toVertex);
    //bool deleteEdge(unsigned int fromVertex, unsigned int toVertex);
    void deleteGraph();
    void printGraph();

    // Algorithms
    bool dfsIterative(unsigned int vertex);

    bool loadFromFile(std::string filename);
    //saveToFile(nombre)
    bool saveToFile(std::string filename);

private:

    class Edge {
    public:
        // Constructor
        Edge(unsigned int toVertex);

        // The destination vertex of the edge
        unsigned int target;

        //Edge weight missing

        friend std::ostream& operator<<(std::ostream &os, const Edge &a) {
            return os << a.target;
        }
    };

    class Vertex {
    public:
        // A linked list to store edges
       unsigned int id;
        LinkedList<Edge> edges;
    };

    unsigned int vertexCount;
    Vertex *vertices;

    bool isValidNumeric(const std::string& str);
};
