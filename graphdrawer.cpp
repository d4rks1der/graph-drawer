#include "graphdrawer.h"
#include "ui_graphdrawer.h"
#include <algorithm>
#include <QResizeEvent>
#include <QDebug>
#include <QString>
#include <QFileDialog>

#include<set>
using std::set;

/* initialization */
GraphDrawer::GraphDrawer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GraphDrawer)
{
    ui->setupUi(this);

    QGraphicsScene *scene = new QGraphicsScene(ui->DrawingArea);
    ui->graphicsView->setScene(scene);
    g = new Graph();
    int rad = std::min(ui->DrawingArea->width(), ui->DrawingArea->height());
    dr = new Drawing(scene,
                     *(new QPen(Qt::black)),
                     g,
                     rad * 17 / 40);
//     //demonstration
//    const int NUM = 7;
//    for (int i = 0; i < NUM; i++) {
//        g->addVertex();
//        ui->DeleteVertexSelector->addItem(QString::number(g->g.size()));
//    }
//    for (int i = 1; i <= NUM; i++)
//        for (int j = i + 1; j <= NUM; j++)
//            if (j <= NUM)
//                g->addEdge(i, j, 5);
//    g->deleteEdge(4, 14);
//    g->deleteVertex(1);
//    dr->drawGraph();
//     //demonstration

}




GraphDrawer::~GraphDrawer()
{
    delete ui;
}



/* draw scaling */
void GraphDrawer::resizeEvent(QResizeEvent *event)
{
    //int width = event->size().width();
    //int height = event->size().height();
    //int oldWidth = event->oldSize().width();
    //int oldHeight = event->oldSize().height();
    int rad = std::min(ui->DrawingArea->width(), ui->DrawingArea->height());
    dr->radius = rad * 17 / 40;
    dr->x0 = dr->radius * 22 / 20;
    dr->y0 = dr->radius * 23 / 20;

    dr->drawGraph();
}




void GraphDrawer::on_AddVertexButton_clicked()
{
    g->addVertex();
    ui->DeleteVertexSelector->addItem(QString::number(g->g.size()));
    ui->AddEdgeV1Selector->addItem(QString::number(g->g.size()));
    ui->AddEdgeV2Selector->addItem(QString::number(g->g.size()));
    dr->drawGraph();

}




void GraphDrawer::on_DeleteVertexButton_clicked()
{
    int delVertex = ui->DeleteVertexSelector->currentIndex();

    int count = g->edges.size();
    //deleting the whole graph when only 1 vertex left
    if (g->g.size() < 2) {
        g->clearGraph();
        ui->AddEdgeV1Selector->clear();
        ui->AddEdgeV2Selector->clear();
        ui->DeleteEdgeSelector->clear();
        ui->DeleteVertexSelector->clear();
        ui->weightInput->clear();
    }
    //deleting vertex in the middle and re-counting new values for vertices
    else if (delVertex < g->g.size() - 1) {
        ui->DeleteVertexSelector->clear();
        ui->AddEdgeV1Selector->clear();
        ui->AddEdgeV2Selector->clear();
        QStringList *list = new QStringList();
        for (int i = 0; i < g->g.size() - 1; i++)
            list->push_back(QString::number(i + 1));

        ui->DeleteVertexSelector->addItems(*list);
        ui->AddEdgeV1Selector->addItems(*list);
        ui->AddEdgeV2Selector->addItems(*list);
        g->deleteVertex(delVertex + 1);
    }
    // deleting vertex in the end
    else {
        ui->DeleteVertexSelector->removeItem(delVertex);
        ui->AddEdgeV1Selector->removeItem(delVertex);
        ui->AddEdgeV2Selector->removeItem(delVertex);
        g->deleteVertex(delVertex + 1);
    }
    if (g->edges.size() != count) {
        ui->DeleteEdgeSelector->clear();
        for (auto it = g->edges.begin(); it != g->edges.end(); it++)
        {
            int weight = it->second;
            int v1 = it->first.first;
            int v2 = it->first.second;
            ui->DeleteEdgeSelector->addItem(QString::number(v1) + '-' + QString::number(v2) + " (" + QString::number(weight) + ')');
        }
    }
    dr->drawGraph();
}




void GraphDrawer::on_AddEdgeButton_clicked()
{
    int weight = ui->weightInput->text().trimmed().toInt();
    int v1 = ui->AddEdgeV1Selector->currentText().toInt();
    int v2 = ui->AddEdgeV2Selector->currentText().toInt();
    int sz = g->edges.size();
    g->addEdge(v1, v2, weight);
    if (sz < g->edges.size())
        ui->DeleteEdgeSelector->addItem(QString::number(v1) + '-' + QString::number(v2) + " (" + QString::number(weight) + ')');
    dr->drawGraph();
}




void GraphDrawer::on_DeleteEdgeButton_clicked()
{
    QString text = ui->DeleteEdgeSelector->currentText();
    if (text.trimmed() == "")
        return;
    QStringList cur_edge = text.split(QRegExp("[\- )()]+"));
    int v1 = cur_edge.at(0).toInt();
    int v2 = cur_edge.at(1).toInt();
    int w = cur_edge.at(2).toInt();
    g->deleteEdge(v1, v2);
    dr->drawGraph();
    ui->DeleteEdgeSelector->removeItem(ui->DeleteEdgeSelector->currentIndex());
}



/* overriting operator < for edges */
bool operator <(const std::pair<std::pair<int, int>, int> &v1, const std::pair<std::pair<int, int>, int> &v2)
{
    return v1.second < v2.second;
}

bool compareEdges(const std::pair<std::pair<int, int>, int> &v1, const std::pair<std::pair<int, int>, int> &v2)
{
    return v1.second < v2.second;
}

void GraphDrawer::on_kruskalRunButton_clicked()
{
    const int N = g->g.size();
    vector<int> tree(N);
    vector<std::pair<std::pair<int, int>, int>> result;
    for (int i = 0; i < N; i++)
        tree[i] = i;
    int cost = 0;

    qDebug() << "Unsorted edges";
    for (int i = 0; i < g->edges.size(); i++)
    {
        qDebug() << g->edges[i].first.first + 1 << g->edges[i].first.second + 1 << '(' << g->edges[i].second << ')';
    }

    std::sort(g->edges.begin(), g->edges.end(), compareEdges);

    qDebug() << "Sorted edges";
    for (int i = 0; i < g->edges.size(); i++)
    {
        qDebug() << g->edges[i].first.first + 1 << g->edges[i].first.second + 1 << '(' << g->edges[i].second << ')';
    }

    for(auto it = g->edges.begin(); it != g->edges.end(); it++)
    {
        if (tree[it->first.first] != tree[it->first.second]) {
                cost += it->second;
                result.push_back(*it);

                int old_id = tree[it->first.first], new_id = tree[it->first.second];
                for (int i = 0; i < N; i++) {
                    if (tree[i] == old_id)
                        tree[i] = new_id;
                }
            }
    }

    vector<std::pair<int, int>>resultDraw;
    qDebug() << "Kruskal result:";
    for (auto it = result.begin(); it != result.end(); it++)
    {
        qDebug() << it->first.first + 1 << it->first.second + 1 << '(' << it->second << ')';
        resultDraw.push_back(it->first);
    }
    dr->markEdges(resultDraw);
}



/* saving to file */
void GraphDrawer::on_actionSave_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "select file", "", "Graph (*.gph);;All Files(*)");
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream out(&file);

    out << g->g.size() << '\n';
    for (auto it = g->edges.begin(); it!= g->edges.end(); it++)
    {
        out << it->first.first + 1 << ' ' << it->first.second + 1 << ' ' << it->second << '\n';
    }
    file.close();
}



/* loading from file */
void GraphDrawer::on_actionLoad_triggered()
{
    g->clearGraph();
    g->edges.clear();
    QString filename = QFileDialog::getOpenFileName(this, "select file", "", "Graph (*.gph);;All Files(*)");
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly))
        return;
    QTextStream in(&file);

    int verticesCount = 0;
    if (!in.atEnd())
    {
        verticesCount = in.readLine().trimmed().toInt();
        for (int i = 0; i < verticesCount; i++) {
                g->addVertex();
                QString v = QString::number(g->g.size());
                ui->DeleteVertexSelector->addItem(v);
                ui->AddEdgeV1Selector->addItem(v);
                ui->AddEdgeV2Selector->addItem(v);
        }
    }

    while(!in.atEnd())
    {
        QStringList line = in.readLine().split(" ");
        int v1 = line.at(0).toInt(), v2 = line.at(1).toInt(), w = line.at(2).toInt();
        int sz = g->edges.size();
        g->addEdge(v1, v2, w);
        if (sz < g->edges.size())
            ui->DeleteEdgeSelector->addItem(QString::number(v1) + '-' + QString::number(v2) + " (" + QString::number(w) + ')');
    }
    file.close();
    dr->drawGraph();
}

void GraphDrawer::on_clearGraphButton_clicked()
{
    g->clearGraph();
    dr->drawGraph();
    ui->AddEdgeV1Selector->clear();
    ui->AddEdgeV2Selector->clear();
    ui->DeleteEdgeSelector->clear();
    ui->DeleteVertexSelector->clear();
    ui->weightInput->clear();
}
