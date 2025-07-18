#ifndef TAB_ITEM_MODEL_H
#define TAB_ITEM_MODEL_H

#include <QAbstractItemModel>
#include <QModelIndex>
#include <QTableView>

class TabItemModel : public QAbstractItemModel
{
public:
    explicit TabItemModel(QObject* parent = nullptr);
    ~TabItemModel();
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    virtual QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    virtual QModelIndex parent(const QModelIndex &index) const  override;
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
};

#endif // TAB_ITEM_MODEL_H
