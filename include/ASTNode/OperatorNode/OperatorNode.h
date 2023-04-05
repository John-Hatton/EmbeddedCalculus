//
// Created by John on 4/3/2023.
//

#pragma once

#include <ASTNode/ASTNode.h>

// Forward declaration of NodeType
enum class NodeType;

/**
 * Class Description OperatorNode: a class that represents a binary operator in the abstract syntax tree.
 * This class is derived from the ASTNode base class and has a left and right child node, representing the operands
 * of the operator. Each operator node also has a char representing the operator being used.
 */
class OperatorNode : public ASTNode {
private:
    ASTNode* leftChild;
    ASTNode* rightChild;
    const std::string& op;

protected:
    OperatorNode(const std::string &op);

public:
    /**
     * OperatorNode Constructor: creates a new operator node with the provided left and right child nodes, and
     * operator character.
     * @param left The left child node.
     * @param right The right child node.
     * @param op The character representing the operator being used.
     */
    OperatorNode(ASTNode* left, ASTNode* right, const std::string& op);

    /**
     * OperatorNode Destructor: cleans up the left and right child nodes.
     */
    ~OperatorNode();

    /**
     * GetLeftChild Function: gets the left child node.
     * @return Returns the left child node.
     */
    ASTNode* getLeftChild() const;

    /**
     * GetRightChild Function: gets the right child node.
     * @return Returns the right child node.
     */
    ASTNode* getRightChild() const;

    /**
     * GetOperator Function: gets the operator character.
     * @return Returns the operator character.
     */
    const std::string& getOperator() const;

    /**
     * GetType Function: gets the NodeType representing this node's type, which is NodeType::OPERATOR_NODE.
     * @return Returns the NodeType representing this node's type.
     */
    typename ASTNode::NodeType getType() const override;

    /**
     * ToString Function: returns a string representation of the node in the format "(leftChild op rightChild)".
     * @return Returns the string representation of the node.
     */
    std::string toString() const override;
};