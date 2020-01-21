#ifndef UIEDGE_H
#define UIEDGE_H

#include <QObject>

#include "uinode.h"

class UIEdge : public QObject
{
    Q_OBJECT
public:

    explicit UIEdge(QModelIndex& from, QModelIndex& to, QObject *parent = nullptr);
    UIEdge(const UIEdge& other);

    UIEdge& operator=(const UIEdge& other);

    const QModelIndex& getFrom() const;
    const QModelIndex& getTo() const;

private:
    QModelIndex m_from;
    QModelIndex m_to;

signals:

public slots:
};

#endif // UIEDGE_H
