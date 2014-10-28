
#include <iostream>

#include "car.h"
#include "node.h"
#include "node_graph.h"
#include "node_search.h"

using namespace traffic;

int main(int argc, char* argv[])
{
    auto rochester = std::make_shared<Node>("Rochester");
    auto buffalo = std::make_shared<Node>("Buffalo");
    auto syracuse = std::make_shared<Node>("Syracuse");
    
    Node::LinkNeighbors(rochester, buffalo, 60.0);
    Node::LinkNeighbors(rochester, syracuse, 90.0);
    Node::LinkNeighbors(buffalo, syracuse, 180.0);
    
    auto graph = std::make_shared<NodeGraph>();
    graph->AddVertex(rochester);
    graph->AddVertex(buffalo);
    graph->AddVertex(syracuse);
    
    Car car(buffalo);
    car.SetAvgVelocity(30);
    
    auto searcher = std::make_shared<NodeSearch>(graph);
    
    car.SetDestination(searcher->FindShortestPath(buffalo, syracuse));
    for(int i = 0; i < 6; i++)
    {
        car.Advance();
        std::cout << "Car's current location: " << car.GetLocation()->GetName() << std::endl;
    }
    
    return 0;
}