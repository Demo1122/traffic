
#include "seed/node_gen.h"

namespace traffic
{

    const std::string tgz_delimiter("#");

    std::vector<std::shared_ptr<Node>> NodeGen::GetNodes()
    {
        bool first_section = true;
        std::string line;
        std::vector<std::shared_ptr<Node>> nodes;
        std::ifstream file ("sample_nodes.tgf");
        std::map<int, std::shared_ptr<Node>> node_map;

        if(file.is_open())
        {
            while(getline(file, line))
            {
                if(tgz_delimiter.compare(line) == 0)
                {
                    first_section = false;
                }
                else if(first_section)
                {
                    std::istringstream iss(line);
                    std::string id, name;
                    getline(iss, id, ' ');
                    getline(iss, name);
                    auto node = std::make_shared<Node>(name);
                    node_map[std::stoi(id)] = node;
                }
                else
                {
                    std::istringstream iss(line);
                    std::string sid1, sid2, sdistance;
                    int id1, id2;
                    double distance;
                    getline(iss, sid1, ' ');
                    getline(iss, sid2, ' ');
                    getline(iss, sdistance);
                    id1 = stoi(sid1);
                    id2 = stoi(sid2);
                    distance = stod(sdistance);
                    Node::LinkNeighbors(node_map[id1], node_map[id2], distance);
                }
            }
            file.close();
        }
        else
        {
            std::cout << "Unable to open file\n";
        }

        for(std::map<int, std::shared_ptr<Node>>::iterator iter = node_map.begin(); iter != node_map.end(); ++iter)
        {
            nodes.push_back(iter->second);
        }

        return nodes;
    }
}
