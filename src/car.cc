
#include "car.h"

namespace traffic
{
    Car::Car(std::shared_ptr<Node> startLoc)
    {
        location = startLoc;
    }
    
    void Car::SetDestination(std::shared_ptr<Node> dest)
    {
        destination = dest;
        distanceRemaining = location->GetDistanceFrom(dest);
    }
    
    std::shared_ptr<Node> Car::GetLocation()
    {
        return location;
    }
    
    bool Car::Advance()
    {
        distanceRemaining -= avgVelocity/6;
        if(distanceRemaining <= 0)
        {
            location = destination;
        }
    }
    
    void Car::setAvgVelocity(float vel)
    {
        avgVelocity = vel;
    }
}