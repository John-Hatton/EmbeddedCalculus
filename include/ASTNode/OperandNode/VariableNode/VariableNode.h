//
// Created by John on 4/4/2023.
//

#pragma once

#include <ASTNode/OperandNode/OperandNode.h>

class VariableNode : public OperandNode<std::string> {
public:
    /**
     * VariableNode Constructor: Constructs a VariableNode with the specified variable name.
     * @param variableName The name of the variable represented by this VariableNode.
     */
    explicit VariableNode(const std::string& variableName);

    /**
     * GetType Function: Returns the node type of this VariableNode.
     * @return The NodeType::VARIABLE_NODE value.
     */
    typename ASTNode::NodeType getType() const override;
};