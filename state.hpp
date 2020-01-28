#include <string>

#ifndef GRAPH_H
#include "graph.hpp"
#endif

#ifndef VEHICLE_H
#include "vehicle.hpp"
#endif

#define STATE_H

class State {
    private:
        vector<State*> pickup();
        vector<State*> deliver();
        vector<State*> move();
    public:
        Vehicle vehicle;
        Graph graph;
        State* parent;

        // Constructor from a copy of it's parent
        State(const State &parent_){
            this->vehicle = parent_.vehicle;
            this->graph = parent_.graph;
        };

        void setParent(State *parent_){
            this->parent = parent_;
        }
        
        // Constructor from initial file (for inital state)
        State(string input_file);
        // Default destructor
        ~State(){};

        vector<State*> getSuccessors();

        void print();
};