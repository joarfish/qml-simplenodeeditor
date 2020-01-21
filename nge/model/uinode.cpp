#include "uinode.h"

UINode::UINode()
    : m_label("Label"), m_type_name("Unknown"), m_position(20.0, 20.0), m_parent()
{

}

UINode::UINode(const UINode &other) { 
    m_label = other.getLabel();
    m_type_name = other.getTypeName();
    m_position = other.getPosition();
}

UINode::~UINode() {
}

UINode::UINode(QString label, QString type_name) :
    m_label(label), m_type_name(type_name), m_position(20.0, 20.0), m_parent()
{
    
}

UINode& UINode::operator=(const UINode &other) {
    m_type_name = other.getTypeName();
    m_label = other.getLabel();
    m_position = other.getPosition();
    
    return *this;
}

QString UINode::getLabel() const {
    return m_label;
}

QString UINode::getTypeName() const { 
    return m_type_name;
}

QModelIndex UINode::getParent() const { 
    return m_parent;
}

QPointF UINode::getPosition() const {
    return m_position;
}

void UINode::setPosition(QPointF &position) {
    m_position = position;
}
