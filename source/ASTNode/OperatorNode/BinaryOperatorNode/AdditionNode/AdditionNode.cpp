//
// Created by John on 4/4/2023.
//

#include "ASTNode/OperatorNode/BinaryOperatorNode/AdditionNode/AdditionNode.h"

template<typename T>
AdditionNode<T>::AdditionNode(std::shared_ptr<ASTNode*> left, std::shared_ptr<ASTNode*> right) : BinaryOperatorNode<T>(left, right) {}

template<typename T>
T AdditionNode<T>::evaluate() {
    T leftVal = this->left->evaluate();
    T rightVal = this->right->evaluate();
    return leftVal + rightVal;
}