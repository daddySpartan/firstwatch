#include "PriorityQueue.h"
#include "Simulation.h"
// Customized comparison function for priority queue Transition struct to change default maximum heap into minimum heap
bool CompareTransition::operator()(const Transition& t1, const Transition& t2) const {
    return t1.time > t2.time;
}
