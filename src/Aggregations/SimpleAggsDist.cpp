#include "SimpleAggsDist.h"
#include "SimpleAggs.h"
#include <vector>
#include <iostream>

namespace calcs
{
    int AllocateAndAggregateDist(int containerSize, int fillValue)
    {
        // TODO: make session available here, for ex. from some singleton class storing SessionHandler
        // auto result = session.GetHub()->call("AllocateAndAggregate", containerSize, fillValue).as<int>();

        // TODO: make the funtion making calls in parallel on many nodes 
        // (simple parallelism in C++ with saving res to vector will be probably enough)

        return 5;
    }
}  // namespace calcs
