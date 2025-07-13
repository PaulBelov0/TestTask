#include "main_window.h"

MainWindow::MainWindow(QString path, QWidget *parent)
    : QMainWindow(parent)
    , m_dataController(new DataController(this))
{
    setMinimumSize(800, 600);

    QSplitter* splitter = new QSplitter(Qt::Horizontal, this);
    setCentralWidget(splitter);
    splitter->setStretchFactor(1, 1);

    TreeViewField* treeViewField = new TreeViewField(path, splitter);
    TableViewField* tableViewField = new TableViewField(splitter);

    connect(this, &MainWindow::resizeEvent, [this, tableViewField, treeViewField, splitter]{
        splitter->resize(this->size());
        treeViewField->resize(static_cast<int>(width() * 0.33), height());
        tableViewField->resize(static_cast<int>(width() * 0.67), height());
    });
}

