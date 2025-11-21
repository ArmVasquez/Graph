#include <iostream>
#include <new>
#include <string>
#include <cctype>
#include "graph.h"
#include "Stack.h"

using namespace std;

Graph::Graph() {
    // Constructor
	vertices = nullptr;
	vertexCount = 0;
}

Graph::~Graph() {
    // Destructor
    deleteGraph();
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
        if (it->target == toVertex) {
            return false; 
        }
    }

    // Creating an edge and inserting it
    Edge newEdge(toVertex);
    Edge reverseEdge (fromVertex);

    if (!vertices[fromVertex].edges.insertAtEnd(newEdge) || !vertices[toVertex].edges.insertAtEnd(reverseEdge)) {
        return false;
    }

    return true;
}

/*bool Graph::deleteEdge(unsigned int fromVertex, unsigned int toVertex) {
    //Validating origin vertex
    if (fromVertex > vertexCount - 1) {
        return false;
    }

    //Validating destination vertex
    if (toVertex > vertexCount - 1) {
        return false;
    }

    // Check if the edge list is empty
    if (vertices[fromVertex].edges.begin() == vertices[fromVertex].edges.end()) {
        return false;
    }

    // Find position of the edge to delete
 
    
    // Delete the edge at the found position
    if (!vertices[fromVertex].edges.deleteElement(position)) {
        return false;
    }
    
    return true;
}*/

void Graph::deleteGraph() {
    // Validating if graph exists
    if (!vertices) {
        return;
    }

    // Deleting lists of edges
    for (unsigned int i = 0; i < vertexCount; i++) {
        vertices[i].edges.deleteList();
    }

    // Liberating array
    delete [] vertices;
    vertices = nullptr;
    vertexCount = 0;
}

void Graph::printGraph() {
    cout << "Graph" << endl;
    
    for (unsigned int i = 0; i < vertexCount; i++) {
        cout << "[" << vertices[i].id << "]" << " -> ";

        for (auto itEdges = vertices[i].edges.begin(); itEdges != vertices[i].edges.end(); itEdges++) {
            cout << *itEdges << " ";
        }

        cout << endl;
    }
}

bool Graph::dfsIterative(unsigned int vertex) {
    // Validating starting vertex
    if (vertex > vertexCount - 1) {
        return false;
    }

    //Resetting visited attributes
    clearVisited();

    //Creating stack
    Stack<unsigned int> stack;
    stack.push(vertex);

    cout << "DFS (" << vertex << "): ";

    while (!stack.isEmpty()) {
        unsigned int currentVertex = *stack.getTop();
        stack.pop();

        if (!vertices[currentVertex].visited) {
            vertices[currentVertex].visited = true;
            std::cout << currentVertex << " ";

            LinkedList<Edge>::Iterator it = vertices[currentVertex].edges.begin();
            while (it != vertices[currentVertex].edges.end()) {
                if (!vertices[it->target].visited) {
                    stack.push(it->target);
                }
                ++it;
            }
        }
    }

    cout << "\n";

    return true;
}

void Graph::clearVisited() {
    for (unsigned int i = 0; i < vertexCount; ++i) {
        vertices[i].visited = false;
    }
}


bool Graph::isValidNumeric(const std::string& str) {
    // Check if string is empty
    if (str.empty()) {
        return false;
    }
    
    // Check each character is a digit
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    
    // String contains only digits, so it's a valid numeric string
    return true;
}