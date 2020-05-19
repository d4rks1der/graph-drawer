#ifndef GRAPHDRAWER_H
#define GRAPHDRAWER_H

#include <QMainWindow>
#include <QGraphicsView>
#include "graph.h"
#include "drawing.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GraphDrawer; }
QT_END_NAMESPACE

class GraphDrawer : public QMainWindow
{
    Q_OBJECT

virtual void resizeEvent(QResizeEvent *event) override;

public:
    GraphDrawer(QWidget *parent = nullptr);
    ~GraphDrawer();
    Drawing *dr;
    Graph *g;

private slots:
    void on_AddVertexButton_clicked();

    void on_DeleteVertexButton_clicked();

    void on_AddEdgeButton_clicked();

    void on_DeleteEdgeButton_clicked();

    void on_kruskalRunButton_clicked();

    void on_actionSave_triggered();

    void on_actionLoad_triggered();

    void on_clearGraphButton_clicked();

private:
    Ui::GraphDrawer *ui;


};
#endif // GRAPHDRAWER_H
