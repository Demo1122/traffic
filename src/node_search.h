
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
        // Use dijkstra's algorithm to find the shortest path to the destination
        void Dijkstra(std::shared_ptr<NodeGraph> graph, std::shared_ptr<Node> src);
        
        // Get the shortest path after Dijkstra's algorithm has been run
        std::stack<std::shared_ptr<Node>> FindShortestPath(std::shared_ptr<Node> dst);
        
        private:
        std::shared_ptr<Node> GetClosestNode(std::set<std::shared_ptr<Node>> q, std::map<std::shared_ptr<Node>, double> dist);
        
        std::map<std::shared_ptr<Node>, double> dist;
        std::map<std::shared_ptr<Node>, std::shared_ptr<Node>> prev;
        
    };
}

#endif