#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <utility>

using std::vector;
using std::pair;

class Graph
{
public:
    vector<vector<int>> g;
    vector<pair<int, int>> edges;

    Graph();
    void addVertex();
    void addEdge(int v1, int v2, int weight);
    void deleteVertex(int v);
    void deleteEdge(int v1, int v2);
    void clearGraph();
    bool isVertexExists(int v); //returns true if vertex v exists
    bool isEdgeExists(int v1, int v2); //returns true if edge (v1, v2) or (v2, v1) exists
};

#endif // GRAPH_H
