
#include "node.h"

namespace traffic
{
    Node::Node(std::string newName)
    {
        name = newName;
    }
    
    void Node::LinkNeighbors(std::shared_ptr<Node> node1, std::shared_ptr<Node> node2, double distance)
    {
        node1->neighbors[node2] = distance;
        node2->neighbors[node1] = distance;
    }
    
    double Node::GetDistanceFrom(std::shared_ptr<Node> node)
    {
        double distance = -1;
        
        distance = neighbors[node];
        
        return distance;
    }
    
    std::string Node::GetName()
    {
        return name;
    }
    
    std::map<std::shared_ptr<Node>, double> Node::GetNeighbors()
    {
        return neighbors;
    }
}