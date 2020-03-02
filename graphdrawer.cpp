#include "graphdrawer.h"
#include "ui_graphdrawer.h"
#include <algorithm>
#include <QResizeEvent>

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

    dr = new Drawing(scene,
                     *(new QPen(Qt::black)),
                     g,
                     std::min(ui->DrawingArea->width(), ui->DrawingArea->height()) * 8 / 20);
    dr->drawGraph();

}

void GraphDrawer::resizeEvent(QResizeEvent *event)
{
    int width = event->size().width();
    int height = event->size().height();
    //int oldWidth = event->oldSize().width();
    //int oldHeight = event->oldSize().height();

    dr->radius = std::min(width, height) * 8 / 20;
    dr->x0 = dr->radius / 8 * 10;
    dr->y0 = dr->radius / 9 * 10;
    dr->drawGraph();

}

GraphDrawer::~GraphDrawer()
{
    delete ui;
}
