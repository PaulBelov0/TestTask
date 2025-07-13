#include "tree_view_field.h"

TreeViewField::TreeViewField(QString path, QWidget *parent)
    : QWidget{parent}
{
    m_treeWidget = new QTreeWidget(this);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(m_treeWidget);

    QTreeWidgetItem* archiveItem = new QTreeWidgetItem(m_treeWidget, 0);
    archiveItem->setText(0, "Архив: " + getArchiveName(path));
    archiveItem->setText(1, "Поиск начат.");

    QTreeWidgetItem* resultItem = new QTreeWidgetItem(m_treeWidget, 0);
    resultItem->setText(0, "Результаты поиска");

    m_treeWidget->addTopLevelItem(archiveItem);
}

QString TreeViewField::getArchiveName(QString path)
{
    std::list<QChar> charName;
    QString result = "";

    for (qsizetype i = path.length() - 1; i >= 0; --i)
    {
        if (path.at(i) != '/')
            charName.push_front(path.at(i));
        else
            break;
    }

    for (std::list<QChar>::iterator it = charName.begin(); it != charName.end(); ++it)
        result += it->mirroredChar();

    return result;
}
