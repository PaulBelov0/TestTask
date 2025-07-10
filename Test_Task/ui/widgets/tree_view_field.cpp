#include "tree_view_field.h"

TreeViewField::TreeViewField(QWidget *parent)
    : QWidget{parent}
{
    m_treeWidget = new QTreeWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(m_treeWidget);
    QTreeWidgetItem* item = new QTreeWidgetItem(m_treeWidget, 0);
    item->setText(0, "TestText");
    m_treeWidget->addTopLevelItem(item);
}
