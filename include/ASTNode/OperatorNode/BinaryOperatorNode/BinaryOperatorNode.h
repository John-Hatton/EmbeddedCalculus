//
// Created by John on 4/4/2023.
//

#ifndef EMBEDEDCALCULUS_BINARYOPERATORNODE_H
#define EMBEDEDCALCULUS_BINARYOPERATORNODE_H

#include <ASTNode/ASTNode.h>
#include <memory>
#include "ASTNode/OperatorNode/OperatorNode.h"

/**
 * Class Description BinaryOperatorNode: a templated class that serves as the base class for binary operator nodes in our
 * Embedded Calculus programming language. A binary operator is an operator that takes two operands, such as addition, subtraction,
 * multiplication, division, etc. This class extends the OperatorNode class.
 * @tparam T The type of the operands.
 */
template<typename T>
class BinaryOperatorNode : public OperatorNode {
public:
    /**
     * BinaryOperatorNode Constructor: Creates a BinaryOperatorNode object with two operand nodes and a token type.
     * @param left The left operand node.
     * @param right The right operand node.
     * @param tokenType The token type corresponding to the operator.
     */
    BinaryOperatorNode(std::shared_ptr<ASTNode*> left, std::shared_ptr<ASTNode*> right, const std::string& tokenType)
            : OperatorNode(tokenType), left(std::move(left)), right(std::move(right)) {}

    /**
     * Evaluate Function: Evaluates the operands and applies the binary operator to them.
     * @return Returns the result of applying the binary operator to the operands.
     */
    T evaluate() override = 0;

protected:
    std::shared_ptr<ASTNode*> left; // The left operand node
    std::shared_ptr<ASTNode*> right; // The right operand node
};

#endif //EMBEDEDCALCULUS_BINARYOPERATORNODE_H
