#include <iostream>
#include <fstream>
#include <string>
#ifndef VEHICLE_H
#include "vehicle.hpp"
#endif
#ifndef GRAPH_H
#include "graph.hpp"
#endif
using namespace std;

int main(int argc, char **argv) {
    if (argc!=2){
        cout << "Error: Usage ./vrp input_file" << endl;
        return 0;
    }
    string input_file = argv[1];
    Graph *graph;

    try{
        graph = new Graph(input_file);
    }catch(int e){
        if (e == 404){
            cout << "Unable to open file " << input_file << endl; 
            return 0;
        }
    }

    vector<int> initial = graph->getInitial();
    Vehicle *vehicle = new Vehicle(initial[0], initial[1]);

    graph->print();


    

    return 0;
}