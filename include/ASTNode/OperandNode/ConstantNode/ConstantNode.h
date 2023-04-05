#pragma once

#include <ASTNode/OperandNode/OperandNode.h>

template <typename T>
class ConstantNode : public OperandNode<T> {
public:
    /**
     * ConstantNode Constructor: Constructs a ConstantNode with the specified value.
     * @param value The value of this ConstantNode.
     */
    explicit ConstantNode(const T& value);

    /**
     * GetType Function: Returns the NodeType of this ConstantNode.
     * @return The NodeType of this ConstantNode.
     */
    typename ASTNode::NodeType getType() const override;

    /**
     * ToString Function: Returns a string representation of this ConstantNode.
     * @return A string representation of this ConstantNode.
     */
    std::string toString() const override;
};

// Explicit instantiations
template class ConstantNode<int>;
template class ConstantNode<double>;