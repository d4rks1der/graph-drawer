#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <utility>

using std::vector;
using std::pair;

class Graph
{
public:
    /* data structure for graph is adjacency matrix */
    vector<vector<int>> g;

    /* data structure for edges is vector with each element as 3 integers: v1, v2, weight */
    vector<pair<pair<int, int>, int>> edges;

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
