#include "graph.h"

Graph::Graph()
{
    g = vector<vector<int>>();
}

void Graph::addVertex()
{
    if (!g.empty())
        for (auto it = g.begin(); it != g.end(); it++)
            it->push_back(0);
    g.push_back(vector<int>(g.size() + 1));
}

void Graph::addEdge(int v1, int v2, int w)
{
    g.at(v1 - 1).at(v2 - 1) = w;
}

void Graph::deleteEdge(int v1, int v2)
{
    g.at(v1 - 1).at(v2 - 1) = -1;
}

void Graph::deleteVertex(int v)
{
    for (auto it = g.begin(); it != g.end(); it++)
        it->erase(it->begin() + v);
    g.erase(g.begin() + v);
}
