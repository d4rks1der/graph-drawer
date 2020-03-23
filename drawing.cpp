#include "drawing.h"

Drawing::Drawing(QGraphicsScene *scene, QPen pen, Graph g, int radius)
{
    this->scene = scene;
    pen.setWidth(2);
    this->pen = pen;
    this->radius = radius;
    this->g = g;
    this->x0 = radius * 22 / 20;
    this->y0 = radius * 23 / 20;
}

void Drawing::drawGraph()
{
    scene->clear();
    const int SIZE = g.g.size();
    vertexCoordinates.resize(SIZE);
    QFont font;
    for (int i = 0; i < SIZE; i++) {//loop for setting and drawing vertices and labels
        vertexCoordinates[i].first = x0 + radius * cos(2 * PI / SIZE * i);
        vertexCoordinates[i].second = y0 + radius * sin(2 * PI / SIZE * i);
        ellipse = scene->addEllipse(vertexCoordinates[i].first - 12, vertexCoordinates[i].second - 12, 22, 22, pen);
        text = new QGraphicsSimpleTextItem(ellipse);
        if (i / 10 == 0) {
            QFont fnt("Times", 12);
            text->setX(vertexCoordinates[i].first - 5);
            text->setY(vertexCoordinates[i].second - 8);
        } else {
            QFont fnt("Times", 10);
            text->setX(vertexCoordinates[i].first - 6);
            text->setY(vertexCoordinates[i].second - 10);
        }
        text->setFont(font);
        text->setText(QString::number(i + 1));
    }

    edgeCoordinates.resize(g.edges.size());

    for (int t = 0; t < g.edges.size(); t++) {//loop for setting and drawing edge coordinates
        int v1 = g.edges.at(t).first;
        int v2 = g.edges.at(t).second;

        if (v1 == 0) {
            edgeCoordinates[t].first.setX(vertexCoordinates[v1].first - 12);
            edgeCoordinates[t].first.setY(vertexCoordinates[v1].second);
        } else if (v1 * 2 == SIZE) {
            edgeCoordinates[t].first.setX(vertexCoordinates[v1].first + 10);
            edgeCoordinates[t].first.setY(vertexCoordinates[v1].second - 3);
        } else if (v1 * 4 == SIZE) {
            edgeCoordinates[t].first.setX(vertexCoordinates[v1].first - 1);
            edgeCoordinates[t].first.setY(vertexCoordinates[v1].second - 12);
        } else if (v1 * 3 / 4 == SIZE) {
            edgeCoordinates[t].first.setX(vertexCoordinates[v1].first - 1);
            edgeCoordinates[t].first.setY(vertexCoordinates[v1].second + 3);
        } else {
            edgeCoordinates[t].first.setX(vertexCoordinates[v1].first - 10 * cos(2 * PI / SIZE * v1));
            edgeCoordinates[t].first.setY(vertexCoordinates[v1].second - 6 * sin(2 * PI / SIZE * v1));
        }
        if (v2 == 0) {
            edgeCoordinates[t].second.setX(vertexCoordinates[v2].first - 12);
            edgeCoordinates[t].second.setY(vertexCoordinates[v2].second);
        } else if (v2 * 2 == SIZE) {
            edgeCoordinates[t].second.setX(vertexCoordinates[v2].first + 10);
            edgeCoordinates[t].second.setY(vertexCoordinates[v2].second - 3);
        } else if (v2 * 4 == SIZE) {
            edgeCoordinates[t].second.setX(vertexCoordinates[v2].first - 1);
                    edgeCoordinates[t].second.setY(vertexCoordinates[v2].second - 12);
        } else if (v2 * 3 / 4 == SIZE) {
            edgeCoordinates[t].second.setX(vertexCoordinates[v2].first - 1);
            edgeCoordinates[t].second.setY(vertexCoordinates[v2].second + 3);
        } else {
            edgeCoordinates[t].second.setX(vertexCoordinates[v2].first - 10 * cos(2 * PI / SIZE * v2));
            edgeCoordinates[t].second.setY(vertexCoordinates[v2].second - 6 * sin(2 * PI / SIZE * v2));
        }

        QLine *l = new QLine(edgeCoordinates[t].first, edgeCoordinates[t].second);
        scene->addLine(*l, pen);
    }

}
