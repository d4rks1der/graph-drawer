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

private:
    Ui::GraphDrawer *ui;
    Drawing *dr;
};
#endif // GRAPHDRAWER_H
