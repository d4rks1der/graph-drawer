#include "graphdrawer.h"
#include "ui_graphdrawer.h"
#include <algorithm>

GraphDrawer::GraphDrawer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GraphDrawer)
{
    ui->setupUi(this);

    QGraphicsScene *scene = new QGraphicsScene(ui->DrawingArea);
    //scene.setParent(ui->DrawingArea);
    ui->graphicsView->setScene(scene);
    Graph g;
    g.addVertex();
    g.addVertex();
    g.addVertex();
    g.addVertex();
    g.addVertex();
    g.addVertex();
    g.addVertex();
    g.addVertex();
    g.addVertex();
    g.addVertex();
    g.addVertex();
    g.addVertex();
    g.addVertex();
    Drawing *dr = new Drawing(scene,
                              *(new QPen(Qt::black)),
                              g,
                              std::min(ui->DrawingArea->width(), ui->DrawingArea->height()) * 8 / 20);
    dr->drawGraph();

}

GraphDrawer::~GraphDrawer()
{
    delete ui;
}
