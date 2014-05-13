
#include <iostream>

#include "node.h"
#include "car.h"

using namespace traffic;

int main(int argc, char* argv[])
{
    std::shared_ptr<Node> Rochester (new Node);
    std::shared_ptr<Node> Buffalo (new Node);
    
    Node::LinkNeighbors(Rochester, Buffalo, 60.0);
    
    std::cout << Rochester->GetDistanceFrom(Buffalo) << std::endl;
    
    return 0;
}