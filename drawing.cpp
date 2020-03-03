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
    vertexCoordinates.resize(SIZE);
    QFont font;
    for (int i = 0; i < SIZE; i++){
        vertexCoordinates[i].first = x0 + radius * cos(2 * PI / SIZE * i);
        vertexCoordinates[i].second = y0 + radius * sin(2 * PI / SIZE * i);
        ellipse = scene->addEllipse(vertexCoordinates[i].first - 12, vertexCoordinates[i].second - 12, 22, 22, pen);
        text = new QGraphicsSimpleTextItem(ellipse);
        if (i / 10 == 0){
            QFont fnt("Times", 12);
            text->setX(vertexCoordinates[i].first - 5);
            text->setY(vertexCoordinates[i].second - 10);
        }else{
            QFont fnt("Times", 10);
            text->setX(vertexCoordinates[i].first - 9);
            text->setY(vertexCoordinates[i].second - 10);
        }
        text->setFont(font);
        text->setText(QString::number(i + 1));
    }

    edgeCoordinates.resize(g.edgesCount);
    for (int i = 0; i < g.edgesCount; i++)
    {
        // loop for setting edge coordinates
        /*if (i == 0){
                    edgeCoordinates[i].setX(vertexCoordinates[i].first - 12);
                    edgeCoordinates[i].setY(vertexCoordinates[i].second);
                }
                else if (i * 2 == SIZE){
                    edgeCoordinates[i].setX(vertexCoordinates[i].first + 10);
                    edgeCoordinates[i].setY(vertexCoordinates[i].second - 3);
                }
                else if (i * 4 == SIZE){
                    edgeCoordinates[i].setX(vertexCoordinates[i].first - 1);
                    edgeCoordinates[i].setY(vertexCoordinates[i].second - 12);
                }
                else if (i * 3 / 4 == SIZE){
                    edgeCoordinates[i].setX(vertexCoordinates[i].first - 1);
                    edgeCoordinates[i].setY(vertexCoordinates[i].second + 3);
                }
                else{
                    edgeCoordinates[i].setX(vertexCoordinates[i].first - 12 * cos(2 * PI / SIZE * i));
                    edgeCoordinates[i].setY(vertexCoordinates[i].second - 6 * sin(2 * PI / SIZE * i));
                }*/
    }

}
