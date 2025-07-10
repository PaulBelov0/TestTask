#ifndef TREE_VIEW_FIELD_H
#define TREE_VIEW_FIELD_H

#include <QWidget>
#include <QPointer>
#include <QVBoxLayout>
#include <QTreeWidget>
#include <QTreeWidgetItem>

class TreeViewField : public QWidget
{
    Q_OBJECT
public:
    explicit TreeViewField(QWidget *parent = nullptr);

private:
    QPointer<QTreeWidget> m_treeWidget;
};

#endif // TREE_VIEW_FIELD_H
