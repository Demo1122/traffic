
#ifndef _NODE_GEN_H
#define _NODE_GEN_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "node.h"

namespace traffic
{
    class NodeGen
    {
        public:
        
        static std::vector<std::shared_ptr<Node>> GetNodes();
        
        private:
        
    };
}

#endif
