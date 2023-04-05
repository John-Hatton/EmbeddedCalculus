//
// Created by John on 4/4/2023.
//

#include "ASTNode/OperandNode/VariableNode/VariableNode.h"

VariableNode::VariableNode(const std::string& variableName) : OperandNode<std::string>(variableName) {}

ASTNode::NodeType VariableNode::getType() const {
    return ASTNode::NodeType::VARIABLE_NODE;
}