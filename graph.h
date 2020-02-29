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
    void addEdge(int, int, int);
    void deleteVertex(int);
    void deleteEdge(int, int);
    void clearGraph();
};

#endif // GRAPH_H
