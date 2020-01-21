#ifndef UIEDGEMODEL_H
#define UIEDGEMODEL_H

#include <QObject>
#include <QAbstractItemModel>
#include <QList>

#include "uiedge.h"

class UIEdgeModel : public QAbstractItemModel
{
    Q_OBJECT
public:

    enum UIEdgeRoles {
        FromIndexRole = Qt::UserRole + 1,
        ToIndexRole
    };

    explicit UIEdgeModel(QObject* parent = nullptr);
    UIEdgeModel(const UIEdgeModel& other);
    UIEdgeModel& operator=(const UIEdgeModel& other);


    virtual QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    virtual QModelIndex parent(const QModelIndex &index) const override;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    void addEdge(QModelIndex& from, QModelIndex& to);

protected:
    virtual QHash<int, QByteArray> roleNames() const override;

private:
    QList<UIEdge> m_edges;

};

Q_DECLARE_METATYPE(UIEdgeModel);

#endif // UIEDGEMODEL_H
