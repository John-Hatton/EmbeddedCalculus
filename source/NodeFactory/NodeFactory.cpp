//
// Created by John on 4/4/2023.
//

#include <NodeFactory/NodeFactory.h>


std::unique_ptr<ASTNode> NodeFactory::createNode(TokenType type, std::unique_ptr<ASTNode> left, std::unique_ptr<ASTNode> right) {
    auto it = nodeTypes.find(type);
    if (it != nodeTypes.end()) {
        return it->second(std::move(left), std::move(right));
    }
    return nullptr;
}