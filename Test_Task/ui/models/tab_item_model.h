#ifndef TAB_ITEM_MODEL_H
#define TAB_ITEM_MODEL_H

#include <QAbstractItemModel>
#include <QTableView>

class TabItemModel : public QAbstractItemModel
{
public:
    explicit TabItemModel(QObject* parent = nullptr);
};

#endif // TAB_ITEM_MODEL_H
