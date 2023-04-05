//
// Created by John on 4/3/2023.
//
#ifndef EMBEDEDCALCULUS_ASTNODE_H
#define EMBEDEDCALCULUS_ASTNODE_H



#include <string>

/**
 * Class Description ASTNode: an abstract base class that serves as the parent class for all other node classes in
 * our abstract syntax tree. This class defines the basic functionality that is common to all node types. Each node
 * has a NodeType that identifies its type, and a toString() method that returns a string representation of the node.
 * Additionally, each node has a getType() method that returns its NodeType.
 */
class ASTNode {

public:
    /**
     * ASTNode Destructor: This is a virtual destructor that is set to the default implementation.
     * This allows child classes to define their own destructors while still being able to call the base class
     * destructor.
     */
    virtual ~ASTNode() = default;

    /**
     * GetType Function: This is a pure virtual function that must be overridden by child classes.
     * @return Returns the NodeType representing the type of this Node.
     */
    virtual NodeType getType() const = 0;

    /**
     * ToString Function: This is a pure virtual function that must be overridden by child classes. It
     * @return Returns a std::string representation of the node.
     */
    virtual std::string toString() const = 0;

/**
 * Enum Description NodeType: an enumerated type that identifies the type of the node.
 */
enum class NodeType {
    OPERAND_NODE,
    CONSTANT_NODE,
    VARIABLE_NODE,
    OPERATOR_NODE,
    UNARY_OPERATOR_NODE,
    BINARY_OPERATOR_NODE,
    FUNCTION_NODE,
    TRIG_FUNCTION_NODE,
    SIN_NODE,
    COS_NODE,
    TAN_NODE,
    LOG_FUNCTION_NODE,
    LOG_NODE,
    LN_NODE
};
};

#endif //EMBEDEDCALCULUS_ASTNODE_H