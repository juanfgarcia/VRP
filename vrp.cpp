#include <iostream>
#include <string>
#include <set>
#ifndef STATE_H
#include "state.hpp"
#endif
using namespace std;


struct state_compare {
    bool operator() (const State *lhs, const State *rhs) const {
        return lhs->f < rhs->f;
    }
};

typedef set<State*, state_compare> state_set; 


int main(int argc, char **argv) {
    if (argc!=2){
        cout << "Error: Usage ./vrp input_file" << endl;
        return 0;
    }
    string input_file = argv[1];
   
    State* initial_state = new State(input_file);   
    state_set open;
    open.insert(initial_state);

    for (State* state : initial_state->getSuccessors()){
        open.insert(state);
    }
    
    for (State* state: open){
        cout << state->f << endl;
    }
    return 0;
}