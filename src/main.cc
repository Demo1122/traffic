
#include <iostream>

#include "car.h"
#include "node.h"
#include "node_graph.h"
#include "node_search.h"
#include "seed/node_gen.h"

using namespace traffic;

int main(int argc, char* argv[])
{
    auto nodes = NodeGen::GetNodes();

    auto graph = std::make_shared<NodeGraph>();
    graph->AddVertices(nodes);

    Car car(nodes[0]);
    car.SetAvgVelocity(30);

    auto searcher = std::make_shared<NodeSearch>(graph);

    car.SetDestination(searcher->FindShortestPath(nodes[0], nodes[nodes.size()-1]));
    for(int i = 0; i < 6; i++)
    {
        car.Advance();
        std::cout << "Car's current location: " << car.GetLocation()->GetName() << std::endl;
    }

    return 0;
}
