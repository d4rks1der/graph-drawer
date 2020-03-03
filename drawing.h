#ifndef DRAWING_H
#define DRAWING_H

#include <QDebug>
#include <QGraphicsView>
#include <QPoint>
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
    vector<QPoint> edgeCoordinates;
    Graph g;

    int radius;
    int x0;
    int y0;
    const double PI = 3.14159265;
    vector<pair<int, int>> vertexCoordinates; //

};

#endif // DRAWING_H
