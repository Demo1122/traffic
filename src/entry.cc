
#include <iostream>

#include "node.h"
#include "car.h"

using namespace traffic;

int main(int argc, char* argv[])
{
    std::shared_ptr<Node> Rochester (new Node("Rochester"));
    std::shared_ptr<Node> Buffalo (new Node("Buffalo"));
    Node::LinkNeighbors(Rochester, Buffalo, 60.0);
    
    Car car(Buffalo);
    
    std::cout << "Car's current location: " << car.GetLocation()->GetName() << std::endl;
    std::cout << "Distance between Rochester and Buffalo: " << Rochester->GetDistanceFrom(Buffalo) << std::endl;
    car.DriveTo(Rochester);
    std::cout << "Car's current location: " << car.GetLocation()->GetName() << std::endl;
    
    return 0;
}