#ifndef STATE_H
#include "state.hpp"
#endif

class State_set {
    vector<State*> set;

    void push();
    State* pop();
    bool isEmpty();   
};