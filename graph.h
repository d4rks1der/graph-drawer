#ifndef GRAPH_H
#define GRAPH_H
#include <vector>

using std::vector;

class Graph
{
public:
    vector<vector<int>> g;

    Graph();
    void addVertex();
    void addEdge(int v1, int v2, int weight);
    void deleteVertex(int);
    void deleteEdge(int, int);
    void clearGraph();
    bool isVertexExists(int v); //returns true if vertex v exists
    bool isEdgeExists(int v1, int v2); //returns true if edge (v1, v2) or (v2, v1) exists

    unsigned int edgesCount;
};

#endif // GRAPH_H
