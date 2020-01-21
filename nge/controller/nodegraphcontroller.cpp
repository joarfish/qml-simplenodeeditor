#include <QDebug>
#include "nodegraphcontroller.h"

NodeGraphController::NodeGraphController(QObject *parent)
    : QObject(parent), m_current_node_model{new UINodeModel(this)}, m_current_edge_model{new UIEdgeModel(this)}
{

    auto n1 = m_current_node_model->createNode("test node 1");
    auto n2 = m_current_node_model->createNode("test node 2");
    auto n3 = m_current_node_model->createNode("test node 3");

    m_current_edge_model->addEdge(n1, n2);
    m_current_edge_model->addEdge(n1, n3);

    qDebug() << "NodeGraphController wurde instantiiert!";

    connect(m_current_node_model, &UINodeModel::dataChanged, this, &NodeGraphController::nodeModelChanged);
    
}

UINodeModel* NodeGraphController::getCurrentNodeModel() {
    return m_current_node_model;
}

UIEdgeModel* NodeGraphController::getCurrentEdgeModel() {
    return m_current_edge_model;
}

void NodeGraphController::createNode() {
    m_current_node_model->createNode("menu node");
}
