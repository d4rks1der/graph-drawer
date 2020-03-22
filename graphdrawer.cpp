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
    ui->graphicsView->setScene(scene);
    Graph g;

    const int NUM = 16;

    for (int i = 0; i < NUM; i++)
        g.addVertex();
    for (int i = 1; i <= NUM; i++)
        for (int j = i + 1; j <= NUM; j++)
            if (j <= NUM)
                g.addEdge(i, j, 5);
    g.deleteEdge(4, 7);
    //g.deleteVertex(11);
    int rad = std::min(ui->DrawingArea->width(), ui->DrawingArea->height());
    dr = new Drawing(scene,
                     *(new QPen(Qt::black)),
                     g,
                     rad * 17 / 40);
    dr->drawGraph();
}

void GraphDrawer::resizeEvent(QResizeEvent *event)
{
    int width = event->size().width();
    int height = event->size().height();
    //int oldWidth = event->oldSize().width();
    //int oldHeight = event->oldSize().height();
    int rad = std::min(ui->DrawingArea->width(), ui->DrawingArea->height());
    dr->radius = rad * 17 / 40;
    dr->x0 = dr->radius * 22 / 20;
    dr->y0 = dr->radius * 23 / 20;

    dr->drawGraph();
}

GraphDrawer::~GraphDrawer()
{
    delete ui;
}
