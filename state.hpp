#include <string>

#ifndef GRAPH_H
#include "graph.hpp"
#endif

#ifndef VEHICLE_H
#include "vehicle.hpp"
#endif

#define STATE_H

class State {
    public:
        Vehicle vehicle;
        Graph graph;
        State* parent;

        // Constructor from a copy of it's parent
        State(const State &parent);
        // Constructor from initial file (for inital state)
        State(string input_file);
        // Default destructor
        ~State();
};