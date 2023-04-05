//
// Created by John on 4/4/2023.
//

#include "ASTNode/OperandNode/OperandNode.h"

#include <ASTNode/OperandNode/OperandNode.h>

template<typename T>
OperandNode<T>::OperandNode(const T &value)
        : value(value) {}

template<typename T>
const T &OperandNode<T>::getValue() const {
    return value;
}

// Explicit instantiations
template class OperandNode<int>;
template class OperandNode<double>;
template class OperandNode<std::string>;