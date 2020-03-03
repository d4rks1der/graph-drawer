#include "graph.h"

Graph::Graph()
{
    g = vector<vector<int>>();
    edgesCount = 0;
}

void Graph::addVertex()
{
    if (!g.empty())
        for (auto it = g.begin(); it != g.end(); it++)
            it->push_back(0);
    g.push_back(vector<int>(g.size() + 1));
}

void Graph::addEdge(int v1, int v2, int weight)
{
    g.at(v1 - 1).at(v2 - 1) = weight;
    edgesCount++;
}

void Graph::deleteEdge(int v1, int v2)
{
    g.at(v1 - 1).at(v2 - 1) = -1;
    edgesCount--;
}

void Graph::deleteVertex(int v)
{
    for (auto it = g.begin(); it != g.end(); it++)
        it->erase(it->begin() + v);
    g.erase(g.begin() + v);
}

bool Graph::isVertexExists(int v)
{
    return (v > 0 && v <= g.size());
}

bool Graph::isEdgeExists(int v1, int v2)
{
    return g.at(v1 - 1).at(v2 - 1) > 0;
}
