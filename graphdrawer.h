#ifndef GRAPHDRAWER_H
#define GRAPHDRAWER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class GraphDrawer; }
QT_END_NAMESPACE

class GraphDrawer : public QMainWindow
{
    Q_OBJECT

public:
    GraphDrawer(QWidget *parent = nullptr);
    ~GraphDrawer();

private:
    Ui::GraphDrawer *ui;
};
#endif // GRAPHDRAWER_H
