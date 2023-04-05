//
// Created by John on 4/4/2023.
//

#include "ASTNode/OperandNode/ConstantNode/ConstantNode.h"
#include <sstream>

template <typename T>
ConstantNode<T>::ConstantNode(const T& value) : OperandNode<T>(value) {}

template <typename T>
typename ASTNode::NodeType ConstantNode<T>::getType() const {
    return ASTNode::NodeType::CONSTANT_NODE;
}

template <typename T>
std::string ConstantNode<T>::toString() const {
    std::ostringstream stream;
    stream << this->value;
    return stream.str();
}