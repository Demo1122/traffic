
#include "node_search.h"

namespace traffic
{
    void NodeSearch::Dijkstra(std::shared_ptr<NodeGraph> graph, std::shared_ptr<Node> src)
    {
        std::set<std::shared_ptr<Node>> q;
        std::set<std::shared_ptr<Node>> vertices = graph->GetVertices();
        
        dist[src] = 0;
        
        for(auto it = vertices.begin(); it != vertices.end(); ++it)
        {
            if(*it != src) 
            {
                dist[*it] = -1;
                prev[*it] = nullptr;
            }
            q.insert(*it);
        }
        
        while(!q.empty())
        {
            std::shared_ptr<Node> u = GetClosestNode(q, dist);
            q.erase(u);
            
            std::map<std::shared_ptr<Node>, double> neighbors = u->GetNeighbors();
            for(auto it = neighbors.begin(); it != neighbors.end(); ++it)
            {
                if(q.find(it->first) != q.end())
                {
                    double alt = dist[u] + it->second;
                    if(dist[it->first] == -1 || alt < dist[it->first]) {
                        dist[it->first] = alt;
                        prev[it->first] = u;
                    }
                }
            }
        }
    }
    
    std::stack<std::shared_ptr<Node>> NodeSearch::FindShortestPath(std::shared_ptr<Node> dst)
    {
        std::stack<std::shared_ptr<Node>> s;
        std::shared_ptr<Node> u = dst;
        
        while(prev[u])
        {
            s.push(u);
            u = prev[u];
        }
        return s;
    }
    
    std::shared_ptr<Node> NodeSearch::GetClosestNode(std::set<std::shared_ptr<Node>> q, std::map<std::shared_ptr<Node>, double> dist)
    {
        auto it = q.begin();
        std::shared_ptr<Node> min = *it;
        ++it;
        for(it; it != q.end(); ++it) {
            if(dist[*it] == 0 || (dist[*it] != -1 && dist[*it] < dist[min]))
            {
                min = *it;
            }
        }
        return min;
    }
}