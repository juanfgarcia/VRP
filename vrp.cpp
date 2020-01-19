#include <iostream>
#include <string>
#ifndef STATE_H
#include "state.hpp"
#endif
using namespace std;

int main(int argc, char **argv) {
    if (argc!=2){
        cout << "Error: Usage ./vrp input_file" << endl;
        return 0;
    }
    string input_file = argv[1];
   
    State* initial_state = new State(input_file);

    initial_state->graph.print();
        
    return 0;
}