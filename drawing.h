#ifndef DRAWING_H
#define DRAWING_H


/* class with tools for drawing */


#include <QDebug>
#include <QGraphicsView>
#include <QPoint>
#include <QGraphicsSimpleTextItem>
#include <QtMath>
#include "graph.h"
#include <vector>
#include <utility>

using std::vector;
using std::pair;

class Drawing
{
public:
    Drawing(QGraphicsScene*, QPen, Graph*, int radius);
    void drawGraph();
    void markEdges(vector<pair<int, int>> edges);

    QGraphicsView *graphicsView;
    QGraphicsScene *scene;
    QGraphicsItemGroup *item_group;
    QGraphicsEllipseItem *ellipse;
    QGraphicsRectItem *rectangle;
    QGraphicsSimpleTextItem *text;
    QPen pen;

    vector<pair<QPoint, QPoint>> edgeCoordinates;
    vector<pair<int, int>> vertexCoordinates;
    Graph *g;

    int radius;
    int x0;
    int y0;
    const double PI = 3.14159265;

};

#endif // DRAWING_H
