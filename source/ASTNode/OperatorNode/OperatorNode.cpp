//
// Created by John on 4/4/2023.
//

#include "ASTNode/OperatorNode/OperatorNode.h"
#include <sstream>

OperatorNode::OperatorNode(ASTNode* left, ASTNode* right, const std::string& op) : leftChild(left), rightChild(right), op(op) {}

OperatorNode::~OperatorNode() {
    delete leftChild;
    delete rightChild;
}

ASTNode* OperatorNode::getLeftChild() const {
    return leftChild;
}

ASTNode* OperatorNode::getRightChild() const {
    return rightChild;
}

const std::string& OperatorNode::getOperator() const {
    return op;
}

ASTNode::NodeType OperatorNode::getType() const {
    return NodeType::OPERATOR_NODE;
}

std::string OperatorNode::toString() const {
    std::stringstream ss;
    ss << "(" << leftChild->toString() << " " << op << " " << rightChild->toString() << ")";
    return ss.str();
}

OperatorNode::OperatorNode(const std::string &op) : op(op) {

}
