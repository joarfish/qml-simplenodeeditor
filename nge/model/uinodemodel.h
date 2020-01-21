#ifndef UINODEMODEL_H
#define UINODEMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QHash>
#include <QQmlListProperty>

#include "uinode.h"

class UINodeModel : public QAbstractItemModel
{
    Q_OBJECT
    
public:
    
    enum UINodeRoles {
        TypeRole = Qt::UserRole + 1,
        LabelRole,
        PositionRole
    };
    
    explicit UINodeModel(QObject* parent = nullptr);
    UINodeModel(const UINodeModel& other);
    UINodeModel& operator=(const UINodeModel& other);

    virtual QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    virtual QModelIndex parent(const QModelIndex &index) const override;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QModelIndex createNode(QString label);

signals:
    void connectNodes(UINode* from, UINode* to, int slot);
    
protected:
    virtual QHash<int, QByteArray> roleNames() const override;

private:
    QHash<int, UINode> m_nodes;

};

Q_DECLARE_METATYPE(UINodeModel);

#endif // UINODEMODEL_H
