
#ifndef _NODE_GRAPH_H
#define _NODE_GRAPH_H

#include <memory>
#include <set>

#include "node.h"

namespace traffic
{
    class NodeGraph
    {
        public:
        std::set<std::shared_ptr<Node>> GetVertices();
        
        void AddVertex(std::shared_ptr<Node> v);
        
        private:
        std::set<std::shared_ptr<Node>> vertices;
    };
}

#endif