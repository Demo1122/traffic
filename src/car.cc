
#include "car.h"

namespace traffic
{
    Car::Car(std::shared_ptr<Node> startLoc)
    {
        currentLoc = startLoc;
    }
    
    bool Car::DriveTo(std::shared_ptr<Node> dest)
    {
        currentLoc = dest;
    }
    
    std::shared_ptr<Node> Car::GetLocation()
    {
        return currentLoc;
    }
}