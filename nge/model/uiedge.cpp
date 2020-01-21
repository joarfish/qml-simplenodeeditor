#include "uiedge.h"

UIEdge::UIEdge(QModelIndex& from, QModelIndex& to, QObject *parent) :
    QObject(parent), m_from(from), m_to(to)
{

}

UIEdge::UIEdge(const UIEdge& other) {
    m_from = other.getFrom();
    m_to = other.getTo();
}

UIEdge& UIEdge::operator=(const UIEdge &other) {
    m_from = other.getFrom();
    m_to = other.getTo();

    return *this;
}

const QModelIndex& UIEdge::getFrom() const {
    return m_from;
}

const QModelIndex& UIEdge::getTo() const {
    return m_to;
}


