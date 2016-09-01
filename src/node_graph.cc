
#include "node_graph.h"

namespace traffic
{
    std::set<std::shared_ptr<Node>> NodeGraph::GetVertices()
    {
        return vertices;
    }
    
    void NodeGraph::AddVertex(std::shared_ptr<Node> v)
    {
        vertices.insert(v);
    }

    void NodeGraph::AddVertices(std::vector<std::shared_ptr<Node>> nodes)
    {
        for(const auto& node : nodes)
        {
            this->AddVertex(node);
        }
    }
}
