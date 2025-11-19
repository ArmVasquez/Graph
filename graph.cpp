#include "graph.h"

using namespace std;

Graph::Graph() {
    // Constructor
	vertices = nullptr;
	vertexCount = 0;
}

Graph::~Graph() {
    // Destructor
    //deleteGraph();
}

bool Graph::createGraph(unsigned int vertexCount) {
    //deleteGraph();

    vertices = new(std::nothrow) Vertex[vertexCount];
    if (!vertices) {
        return false;
    }

    this->vertexCount = vertexCount;

    return true;
}

