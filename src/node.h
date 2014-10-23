
#ifndef _NODE_H
#define _NODE_H

#include <map>
#include <memory>
#include <string>

namespace traffic
{
    class Node
    {
        public:
        // Constructor
        Node(std::string newName);
        
        // Add nodes to each other's map of neighbors and vice versa
        // No difference between parameters node1 and node2
        static void LinkNeighbors(std::shared_ptr<Node> node1, std::shared_ptr<Node> node2, double distance);
        
        // Get the distance from a node
        // Returns distance as an int, or -1 if not a neighbor
        int GetDistanceFrom(std::shared_ptr<Node> node);
        
        // Returns the node's name field
        std::string GetName();
        
        std::map<std::shared_ptr<Node>, double> GetNeighbors();
        
        private:
        // Name of the node
        std::string name;
        
        // Map of neighboring node names and distances
        std::map<std::shared_ptr<Node>, double> neighbors;
        
    };
}

#endif