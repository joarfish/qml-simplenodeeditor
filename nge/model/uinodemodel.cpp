#include "uinodemodel.h"
#include <QDebug>
#include <iostream>

UINodeModel::UINodeModel(QObject* parent) : QAbstractItemModel(parent)
{

}


QModelIndex UINodeModel::index(int row, int column, const QModelIndex &parent) const {
    if(m_nodes.contains(row)) {
        return QAbstractItemModel::createIndex(row, column);
    }
    
    return QModelIndex();
}

QModelIndex UINodeModel::parent(const QModelIndex &index) const { 
    return QModelIndex();
}

int UINodeModel::rowCount(const QModelIndex &parent) const {
    return m_nodes.count();
}

QVariant UINodeModel::data(const QModelIndex &index, int role) const {
    QVariant result;
    
    if(!m_nodes.contains(index.row())) {
        return QVariant();
    }
    
    auto node = m_nodes.value(index.row());

    switch(role) {
        case LabelRole: return QVariant(node.getLabel());
        case TypeRole: return QVariant(node.getTypeName());
        case PositionRole: return QVariant(node.getPosition());
        default: break;
    }
    
    return QVariant();
}

UINodeModel &UINodeModel::operator=(const UINodeModel &other) {
    m_nodes = other.m_nodes;
    return *this;
}

UINodeModel::UINodeModel(const UINodeModel &other) { 
    m_nodes = other.m_nodes;
}

QHash<int, QByteArray> UINodeModel::roleNames() const { 
    QHash<int, QByteArray> roles;

    roles[LabelRole] = "label";
    roles[TypeRole] = "nodeType";
    roles[PositionRole] = "position";


    return roles;
}

int UINodeModel::columnCount(const QModelIndex &) const {
    return 1;
}

QModelIndex UINodeModel::createNode(QString label) {

    beginInsertRows(QModelIndex(), m_nodes.count(), m_nodes.count());

   auto it =  m_nodes.insert(m_nodes.count(), UINode(label, "test"));

   auto newElementIndex = index(it.key(),1);

   //emit dataChanged(newElementIndex, newElementIndex);

   qDebug() << "UINodeModel::createNode called.";

   endInsertRows();

   return newElementIndex;
}








