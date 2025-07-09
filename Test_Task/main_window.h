#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QTreeView>
#include <QPointer>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTableView>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void resizeEvent(QResizeEvent *event);

private:
    QPointer<QTreeView> m_treeView;
};
#endif // MAIN_WINDOW_H
