#include "graph.h"

Graph::Graph()
{
    g = vector<vector<int>>();
    edges = vector<pair<int, int>>();
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
    edges.push_back(std::make_pair(v1 - 1, v2 - 1));
}


//NEED TO FIX THIS METHOD
void Graph::deleteEdge(int v1, int v2)
{
    --v1;
    --v2;
    g.at(v1).at(v2) = -1;
    for (auto it = edges.begin(); it != edges.end(); it++)
    {
        if (it->first == v1 && it->second == v2 || it->first == v2 && it->second == v1)
        {
            edges.erase(it);
            break;
        }
    }
}

void Graph::deleteVertex(int v)
{
    for (auto it = g.begin(); it != g.end(); it++)
        it->erase(it->begin() + v);
    g.erase(g.begin() + v);

    for (auto it = edges.begin(); it != edges.end(); it++)
        if (it->first == v || it->second == v)
            edges.erase(it);
}

bool Graph::isVertexExists(int v)
{
    return (v > 0 && v <= g.size());
}

bool Graph::isEdgeExists(int v1, int v2)
{
    return g.at(v1 - 1).at(v2 - 1) > 0;
}

void Graph::clearGraph()
{
    g.clear();
    edges.clear();
}
