#ifndef UINODE_H
#define UINODE_H

#include <QObject>
#include <QMetaType>
#include <QModelIndex>
#include <QPointF>

class UINode : public QObject
{
    Q_OBJECT

public:
    UINode();
    UINode(const UINode &other);
    ~UINode();

    UINode(QString label, QString type_name);
    
    UINode& operator=(const UINode& other);

    QString getLabel() const;
    QString getTypeName() const;
    
    QPointF getPosition() const;
    void setPosition(QPointF& position);

    QModelIndex getParent() const;

private:
    QString m_label;
    QString m_type_name;

    QPointF m_position;

    QModelIndex m_parent;
};


#endif // UINODE_H
