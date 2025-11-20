#include <iostream>
#include <new>
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

Graph::Edge::Edge(unsigned int toVertex) : target(toVertex) {}

bool Graph::createGraph(unsigned int vertexCount) {
    //deleteGraph();

    vertices = new(nothrow) Vertex[vertexCount];
    if (!vertices) {
        return false;
    }

    // Assigning each vertex an id
    for (unsigned int i = 0; i < vertexCount; i++) {
        vertices[i].id = i;
    }

    this->vertexCount = vertexCount;

    return true;
}

bool Graph::insertEdge(unsigned int fromVertex, unsigned int toVertex) {

    //Validating origin vertex

    if (fromVertex > vertexCount - 1) {
        return false;
    }

    //Validating destination vertex
    if (toVertex > vertexCount - 1) {
        return false;
    }

    // Check if edge already exists
    for (auto it = vertices[fromVertex].edges.begin(); it != vertices[fromVertex].edges.end(); it++) {
        if ((*it).target == toVertex) {
            return false; 
        }
    }

    // Creating an edge and inserting it
    Edge newEdge(toVertex);
    if (!vertices[fromVertex].edges.insertAtEnd(newEdge)) {
        return false;
    }
    
    return true;
}

void Graph::printGraph() {
    cout << "Graph" << endl;
    

    // Corregir esta parte
    // Iterate through all vertices
    for (unsigned int i = 0; i < vertexCount; i++) {
        cout << vertices[i].id << " -> ";
        
        // Check if vertex has edges
        if (vertices[i].edges.begin() == vertices[i].edges.end()) {
            cout << "[]" << endl;
        } else {
            // Use LinkedList iterator to iterate through edges
            bool first = true;
            for (auto edgeIt = vertices[i].edges.begin(); edgeIt != vertices[i].edges.end(); edgeIt++) {
                if (!first) {
                    cout << ", ";
                }
                cout << *edgeIt;  // Uses Edge's operator<<
                first = false;
            }
            cout << endl;
        }
    }
}

