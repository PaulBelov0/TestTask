#include "tab_item_model.h"

TabItemModel::TabItemModel(QObject* parent)
    : QAbstractItemModel(parent)
{}

TabItemModel::~TabItemModel()
{}

int TabItemModel::columnCount(const QModelIndex &parent = QModelIndex()) const
{}

QVariant TabItemModel::data(const QModelIndex &index, int role = Qt::DisplayRole) const
{}

QModelIndex TabItemModel::index(int row, int column, const QModelIndex &parent = QModelIndex()) const
{}

QModelIndex TabItemModel::parent(const QModelIndex &index) const
{}

int TabItemModel::rowCount(const QModelIndex &parent = QModelIndex()) const
{}
