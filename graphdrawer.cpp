#include "graphdrawer.h"
#include "ui_graphdrawer.h"

GraphDrawer::GraphDrawer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GraphDrawer)
{
    ui->setupUi(this);
}

GraphDrawer::~GraphDrawer()
{
    delete ui;
}

