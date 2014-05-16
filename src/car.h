
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
        Car(std::shared_ptr<Node> startLoc);
        
        // Advance to destination
        bool DriveTo(std::shared_ptr<Node> dest);
        
        // Get car's location
        std::shared_ptr<Node> GetLocation();
        
        private:
        std::shared_ptr<Node> currentLoc;
    };
}

#endif