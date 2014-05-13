
#include "node.h"

namespace traffic
{
    Node::Node()
    {
    }
    
    bool Node::AddNeighbor(std::shared_ptr<Node> node, double distance)
    {
        neighbors[node] = distance;
        return true;
    }
    
    double Node::GetDistanceFrom(std::shared_ptr<Node> node)
    {
        double distance = -1;
        
        distance = neighbors[node];
        
        return distance;
    }
}