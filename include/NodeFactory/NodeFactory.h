//
// Created by John on 4/4/2023.
//
#ifndef EMBEDEDCALCULUS_NODEFACTORY_H
#define EMBEDEDCALCULUS_NODEFACTORY_H

#include "ASTNode/ASTNode.h"
#include <memory>
#include <map>
#include <functional>

/**
 * Class Description NodeFactory: a class that serves as a factory for creating ASTNode objects.
 * This class provides a simple and extensible way to create ASTNode objects without having to
 * directly call their constructors.
 */
class NodeFactory {
public:
    /**
     * Create Node Function: Creates a new ASTNode object of a specified type with a given left and right child.
     * @tparam T The type of the ASTNode to create.
     * @param left The left child of the new ASTNode.
     * @param right The right child of the new ASTNode.
     * @return Returns a unique_ptr to the new ASTNode.
     */
    template<typename T>
    std::unique_ptr<T> createNode(std::unique_ptr<ASTNode*> left, std::unique_ptr<ASTNode*> right) {
        return std::make_unique<T>(std::move(left), std::move(right));
    }

    /**
     * Register Node Type Function: Registers a new type of ASTNode with the NodeFactory, so that it can be created
     * using the createNode() function.
     * @tparam T The type of the new ASTNode to register.
     */
    template<typename T>
    void registerNodeType() {
        nodeTypes[T::TYPE] = [] (std::unique_ptr<ASTNode> left, std::unique_ptr<ASTNode> right) {
            return std::make_unique<T>(std::move(left), std::move(right));
        };
    }

    /**
     * Create Node Function: Creates a new ASTNode object of a specified type with a given left and right child.
     * @param type The type of the ASTNode to create.
     * @param left The left child of the new ASTNode.
     * @param right The right child of the new ASTNode.
     * @return Returns a unique_ptr to the new ASTNode.
     */
    std::unique_ptr<ASTNode*> createNode(ASTNode::NodeType type, std::unique_ptr<ASTNode*> left, std::unique_ptr<ASTNode*> right);

private:
    std::map<ASTNode::NodeType, std::function<std::unique_ptr<ASTNode*>(std::unique_ptr<ASTNode*>, std::unique_ptr<ASTNode*>)>> nodeTypes;
};

#endif //EMBEDEDCALCULUS_NODEFACTORY_H
