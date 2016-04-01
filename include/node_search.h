
#ifndef _NODE_SEARCH_H
#define _NODE_SEARCH_H

#include <map>
#include <memory>
#include <set>
#include <stack>

#include "node.h"
#include "node_graph.h"

namespace traffic
{
    class NodeSearch
    {
        public:
        
        // Constructor takes a graph that doesn't change over its life
        NodeSearch(std::shared_ptr<NodeGraph> graph);
        
        // Get the shortest path after Dijkstra's algorithm has been run
        std::stack<std::shared_ptr<Node>> FindShortestPath(
            std::shared_ptr<Node> src,
            std::shared_ptr<Node> dst);
            
        
        private:
        
        // Use Dijkstra's algorithm to build a shortest path map
        void Dijkstra(std::shared_ptr<Node> src);
        
        // Get the neighbor with shortest distance to q
        std::shared_ptr<Node> GetClosestNode(std::set<std::shared_ptr<Node>> q, std::map<std::shared_ptr<Node>, double> dist);
        
        // The graph that contains all of the nodes
        std::shared_ptr<NodeGraph> graph;
        
        // The source node
        std::shared_ptr<Node> source;
        
        // Map of closest previous locations
        std::map<std::shared_ptr<Node>, std::shared_ptr<Node>> prev;
        
    };
}

#endif