
#include <iostream>

#include "car.h"
#include "node.h"
#include "node_graph.h"
#include "node_search.h"

using namespace traffic;

int main(int argc, char* argv[])
{
    std::shared_ptr<Node> Rochester (new Node("Rochester"));
    std::shared_ptr<Node> Buffalo (new Node("Buffalo"));
    std::shared_ptr<Node> Syracuse (new Node("Syracuse"));
    
    Node::LinkNeighbors(Rochester, Buffalo, 60.0);
    Node::LinkNeighbors(Rochester, Syracuse, 90.0);
    Node::LinkNeighbors(Buffalo, Syracuse, 140.0);
    
    std::shared_ptr<NodeGraph> graph (new NodeGraph());
    graph->AddVertex(Rochester);
    graph->AddVertex(Buffalo);
    graph->AddVertex(Syracuse);
    
    std::unique_ptr<NodeSearch> searcher (new NodeSearch());
    searcher->Dijkstra(graph, Buffalo);
    
    std::stack<std::shared_ptr<Node>> order = searcher->FindShortestPath(Syracuse);
    
    while (!order.empty())
    {
        std::cout << order.top()->GetName() << std::endl;
        order.pop();
    }
    
    Car car(Buffalo);
    car.setAvgVelocity(60);
    
    while(0) {
        std::cout << "Car's current location: " << car.GetLocation()->GetName() << std::endl;
        std::cout << "Distance between Rochester and Buffalo: " << Rochester->GetDistanceFrom(Buffalo) << std::endl;
        car.SetDestination(Rochester);
        for(int i = 0; i < 10; i++)
        {
            car.Advance();
            std::cout << "Car's current location: " << car.GetLocation()->GetName() << std::endl;
        }
    }
    
    return 0;
}