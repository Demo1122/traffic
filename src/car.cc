
#include <iostream>

#include "car.h"

namespace traffic
{
    Car::Car(std::shared_ptr<Node> start)
    {
        location = start;
    }
    
    void Car::SetDestination(std::stack<std::shared_ptr<Node>> dest)
    {
        destination = dest;
        distanceRemaining = location->GetDistanceFrom(destination.top());
    }
    
    std::shared_ptr<Node> Car::GetLocation()
    {
        return location;
    }
    
    void Car::Advance()
    {
        distanceRemaining -= avgVelocity;
        if(distanceRemaining <= 0 && !destination.empty())
        {
            location = destination.top();
            destination.pop();
            if(!destination.empty())
            {
                distanceRemaining += location->GetDistanceFrom(destination.top());
            }
        }
    }
    
    void Car::SetAvgVelocity(float v)
    {
        avgVelocity = v;
    }
}