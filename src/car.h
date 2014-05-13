
#ifndef _CAR_H
#define _CAR_H

#include <memory>

#include "node.h"

namespace traffic
{
    class Car
    {
        public:
        // Default Constructor
        Car();
        
        // Advance to destination
        void DriveTo(std::shared_ptr<Node> dest);
        
        //private:
    };
}

#endif