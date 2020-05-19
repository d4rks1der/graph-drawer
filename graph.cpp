#include "graph.h"
#include <QDebug>

Graph::Graph()
{
    g = vector<vector<int>>();
    edges = vector<pair<pair<int, int>, int>>();
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
    g.at(v1 - 1).at(v2 - 1) = 1;
    if (!isEdgeExists(v1, v2))
        edges.push_back(std::make_pair(std::make_pair(v1 - 1, v2 - 1), weight));
    //qDebug() << "##";
    //for (int i = 0; i < edges.size(); i++)
        //qDebug() << edges[i].first.first << edges[i].first.second << g.at(edges[i].first.first).at(edges[i].first.second);
}

void Graph::deleteEdge(int v1, int v2)
{
    --v1;
    --v2;
    g.at(v1).at(v2) = 0;
    g.at(v2).at(v1) = 0;
    for (auto it = edges.begin(); it != edges.end(); it++)
    {
        if (it->first.first == v1 && it->first.second == v2 || it->first.first == v2 && it->first.second == v1)
        {
            edges.erase(it);
            break;
        }
    }
}

void Graph::deleteVertex(int v)
{
    --v;
    vector<pair<pair<int, int>, int>> tmp;

    for (auto it = edges.begin(); it != edges.end(); it++) {
        if (it->first.first != v && it->first.second != v)
        {
            if (it->first.first > v)
                it->first.first--;
            if (it->first.second > v)
                it->first.second--;
            tmp.push_back(*it);
        }
    }

    edges = tmp;
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
    --v1;
    --v2;
    for (auto it = edges.begin(); it != edges.end(); it++)
    {
        if ((it->first.first == v1 && it->first.second == v2) || (it->first.first == v2 && it->first.second == v1))
            return true;
    }
    return false;
}

void Graph::clearGraph()
{
    g.clear();
    edges.clear();
}
