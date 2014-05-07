
#ifndef _NODE_H
#define _NODE_H

namespace traffic
{
    class Node
    {
        public:
        Node(int distance);
        
        getDistanceFrom(Node loc);
        
        private:
        int distance;
        
    }
}

#endif _NODE_H