#include "drawing.h"

Drawing::Drawing(QGraphicsScene *scene, QPen pen, Graph g, int radius)
{
    this->scene = scene;
    pen.setWidth(2);
    this->pen = pen;
    this->radius = radius;
    this->g = g;
    this->x0 = radius / 8 * 10;
    this->y0 = radius / 9 * 10;
}

void Drawing::drawGraph()
{
    scene->clear();
    const int SIZE = g.g.size();
    vpos.resize(SIZE);
    for (int i = 0; i < SIZE; i++){
        vpos[i].first = x0 + radius * cos(2 * PI / SIZE * i);
        vpos[i].second = y0 + radius * sin(2 * PI / SIZE * i);
        //qDebug() << vpos[i].first << ' ' << vpos[i].second << '\n';
        scene->addEllipse(vpos[i].first - 12, vpos[i].second - 12, 22, 22, pen);
    }
}
