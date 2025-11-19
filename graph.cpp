#include "graph.h"

using namespace std;

Graph::Graph() {
    // Constructor

}

Graph::~Graph() {
    // Destructor
    //deleteGraph();
}

bool Graph::createGraph(unsigned int vertexCount) {
    //deleteGraph();
    
    Vertex *newVertices = nullptr;

    newVertices = new(std::nothrow) Vertex[vertexCount];
    if (!newVertices) {
        return false;
    }

    this->vertexCount = vertexCount;

    return true;
}

