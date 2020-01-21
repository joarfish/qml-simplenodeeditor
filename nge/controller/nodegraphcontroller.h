#ifndef NODEGRAPHCONTROLLER_H
#define NODEGRAPHCONTROLLER_H

#include <QObject>
#include <nge/model/uinodemodel.h>
#include <nge/model/uiedgemodel.h>

class NodeGraphController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(UINodeModel *nodeModel READ getCurrentNodeModel NOTIFY nodeModelChanged )
    Q_PROPERTY(UIEdgeModel *edgeModel READ getCurrentEdgeModel CONSTANT )
    
public:
    explicit NodeGraphController(QObject *parent = nullptr);
    
    UINodeModel* getCurrentNodeModel();
    UIEdgeModel* getCurrentEdgeModel();

signals:
    void nodeModelChanged();

public slots:
    void createNode();
    
private:
    UINodeModel *m_current_node_model;
    UIEdgeModel *m_current_edge_model;
    
};

#endif // NODEGRAPHCONTROLLER_H
