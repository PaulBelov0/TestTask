#ifndef TREE_ITEM_MODEL_H
#define TREE_ITEM_MODEL_H

#include <QAbstractItemModel>

class TreeItemModel : public QAbstractItemModel
{
public:
    explicit TreeItemModel(QObject* parent = nullptr);
};

#endif // TREE_ITEM_MODEL_H
