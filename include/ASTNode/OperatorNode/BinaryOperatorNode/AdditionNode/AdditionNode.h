#ifndef EMBEDEDCALCULUS_ADDITIONNODE_H
#define EMBEDEDCALCULUS_ADDITIONNODE_H

#include "ASTNode/OperatorNode/BinaryOperatorNode/BinaryOperatorNode.h"

/**
 * Class Description AdditionNode: a class that represents an addition operation in the abstract syntax tree.
 * This class extends the BinaryOperatorNode class and implements the evaluate method.
 * @tparam T The type of the operands of the addition operation.
 */
template<typename T>
class AdditionNode : public BinaryOperatorNode<T> {
public:
    /**
     * AdditionNode Constructor: Creates an AdditionNode object with a given left and right operand.
     * @param left The left operand of the addition operation.
     * @param right The right operand of the addition operation.
     */
    AdditionNode(std::shared_ptr<ASTNode*> left, std::shared_ptr<ASTNode*> right);

    /**
     * Evaluate Function: Evaluates the addition operation and returns the result.
     * @return Returns the result of the addition operation.
     */
    T evaluate() override;
};

#endif //EMBEDEDCALCULUS_ADDITIONNODE_H
