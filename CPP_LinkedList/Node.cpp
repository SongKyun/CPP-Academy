#include "Node.h"

// Ctrl + ;

std::ostream& operator<<(std::ostream& os, const Node& node)
{
    return os << "Date: " << node.data;
}

Node::Node()
    : Node(0)
{

}

Node::Node(int data)
    : data(data), next(nullptr)
{

}