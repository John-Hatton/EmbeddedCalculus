//
// Created by John on 4/4/2023.
//

#pragma once

#include <ASTNode/ASTNode.h>

template <typename T>
class OperandNode : public ASTNode {
public:
    /**
     * OperandNode Constructor: Constructs an OperandNode with the specified value.
     * @param value The value of this OperandNode.
     */
    explicit OperandNode(const T& value);

    /**
     * Getter Function: Returns the value of this OperandNode.
     * @return The value of this OperandNode.
     */
    virtual const T& getValue() const;

protected:
    /**
     * The value of this OperandNode.
     */
    T value;
};