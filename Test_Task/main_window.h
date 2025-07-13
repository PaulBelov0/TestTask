#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QTreeView>
#include <QScopedPointer>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTableView>
#include <QSplitter>

#include "ui/widgets/tree_view_field.h"
#include "ui/widgets/table_view_field.h"
#include "services/data_controller.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setFilePath(QString pathToFile);

signals:
    void resizeEvent(QResizeEvent* ev);

private:
    QScopedPointer<DataController> m_dataController;
};
#endif // MAIN_WINDOW_H
