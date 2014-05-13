
#include "node.h"

namespace traffic
{
    Node::Node()
    {
    }
    
    bool Node::LinkNeighbors(std::shared_ptr<Node> node1, std::shared_ptr<Node> node2, double distance)
    {
        node1->neighbors[node2] = distance;
        node2->neighbors[node1] = distance;
        return true;
    }
    
    double Node::GetDistanceFrom(std::shared_ptr<Node> node)
    {
        double distance = -1;
        
        distance = neighbors[node];
        
        return distance;
    }
}