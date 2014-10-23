
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
        void SetDestination(std::shared_ptr<Node> dest);
        
        // Get car's location
        std::shared_ptr<Node> GetLocation();
        
        // Advance to destination
        bool Advance();
        
        // Set the car's avgVelocity field
        void setAvgVelocity(float vel);
        
        private:
        int distanceRemaining;
        float avgVelocity;
        std::shared_ptr<Node> location;
        std::shared_ptr<Node> destination;
    };
}

#endif