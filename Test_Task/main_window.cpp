#include "main_window.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setMinimumSize(400, 300);

    QWidget* wgt = new QWidget(this);
    layout()->addWidget(wgt);

    m_treeView = new QTreeView(this);

    QHBoxLayout* mainLayout = new QHBoxLayout(wgt);
    mainLayout->addWidget(m_treeView.get());

    QVBoxLayout* tabViewLayout = new QVBoxLayout(this);
    mainLayout->addItem(tabViewLayout);

    QTableView* tabViewTest = new QTableView(this);
    tabViewLayout->addWidget(tabViewTest);

    connect(this, &MainWindow::resizeEvent, [this, wgt]{
        wgt->setFixedSize(this->size());
    });
}

MainWindow::~MainWindow() {}
