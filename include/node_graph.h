
#ifndef _NODE_GRAPH_H
#define _NODE_GRAPH_H

#include <memory>
#include <set>
#include <vector>

#include "node.h"

namespace traffic
{
    class NodeGraph
    {
        public:
        std::set<std::shared_ptr<Node>> GetVertices();
        
        void AddVertex(std::shared_ptr<Node> v);

        void AddVertices(std::vector<std::shared_ptr<Node>> nodes);
        
        private:
        std::set<std::shared_ptr<Node>> vertices;
    };
}

#endif
