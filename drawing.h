#ifndef DRAWING_H
#define DRAWING_H

#include <QDebug>
#include <QGraphicsView>
#include <QGraphicsSimpleTextItem>
#include <QtMath>
#include "graph.h"
//#include <vector>
#include <utility>

using std::vector;
using std::pair;

class Drawing
{
public:
    Drawing(QGraphicsScene*, QPen, Graph, int radius);
    void drawGraph();

    QGraphicsView *graphicsView;
    QGraphicsScene *scene;
    QGraphicsItemGroup *item_group;
    QGraphicsEllipseItem *ellipse;
    QGraphicsRectItem *rectangle;
    QGraphicsSimpleTextItem *text;
    QPen pen;
    vector<pair<int, int>> edgeCoordinates;
    Graph g;

    int radius;
    int x0;
    int y0;
    const double PI = 3.14159265;
    vector<pair<int, int>> vpos; //vertex coordinates(first - x; second - y)

};

#endif // DRAWING_H
