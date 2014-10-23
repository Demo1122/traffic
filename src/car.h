
#ifndef _CAR_H
#define _CAR_H

#include <memory>
#include <stack>

#include "node.h"

namespace traffic
{
    class Car
    {
        public:
        // Default Constructor
        Car(std::shared_ptr<Node> start);
        
        // Advance to destination
        void SetDestination(std::stack<std::shared_ptr<Node>> dest);
        
        // Get car's location
        std::shared_ptr<Node> GetLocation();
        
        // Advance to destination
        void Advance();
        
        // Set the car's average velocity
        void SetAvgVelocity(float v);
        
        private:
        float distanceRemaining;
        float avgVelocity;
        std::shared_ptr<Node> location;
        std::stack<std::shared_ptr<Node>> destination;
    };
}

#endif