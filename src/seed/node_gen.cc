
#include "seed/node_gen.h"

namespace traffic
{
    std::vector<std::shared_ptr<Node>> NodeGen::GetNodes()
    {
        std::string line;
        std::vector<std::shared_ptr<Node>> nodes;
        std::ifstream file ("sample_nodes.txt");

        if(file.is_open())
        {
            while(getline(file, line))
            {
                std::cout << line << std::endl;
            }
            file.close();
        }
        else
        {
            std::cout << "Unable to open file\n";
        }
        return nodes;
    }
}
