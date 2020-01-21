#include "uiedgemodel.h"

UIEdgeModel::UIEdgeModel(QObject* parent) : QAbstractItemModel(parent)
{

}


QModelIndex UIEdgeModel::index(int row, int column, const QModelIndex &parent) const {
    if(m_edges.size() >= row) {
        return QAbstractItemModel::createIndex(row, column);
    }

    return QModelIndex();
}

QModelIndex UIEdgeModel::parent(const QModelIndex &index) const {
    return QModelIndex();
}

int UIEdgeModel::rowCount(const QModelIndex &parent) const {
    return m_edges.count();
}

QVariant UIEdgeModel::data(const QModelIndex &index, int role) const {
    QVariant result;

    if(m_edges.size() < index.row()) {
        return QVariant();
    }

    auto edge = m_edges.at(index.row());

    switch(role) {
        case FromIndexRole: return QVariant(edge.getFrom());
        case ToIndexRole: return QVariant(edge.getTo());
        default: break;
    }

    return QVariant();
}

UIEdgeModel &UIEdgeModel::operator=(const UIEdgeModel &other) {
    m_edges = other.m_edges;
    return *this;
}

UIEdgeModel::UIEdgeModel(const UIEdgeModel &other) {
    m_edges = other.m_edges;
}

QHash<int, QByteArray> UIEdgeModel::roleNames() const {
    QHash<int, QByteArray> roles;

    roles[FromIndexRole] = "from";
    roles[ToIndexRole] = "to";

    return roles;
}

int UIEdgeModel::columnCount(const QModelIndex &) const {
    return 1;
}

void UIEdgeModel::addEdge(QModelIndex& from, QModelIndex& to) {
    m_edges.push_back(UIEdge(from, to));
}

