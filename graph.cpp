#include <fstream>
#include <sstream>
#include <iterator>
#include <iostream>
#ifndef GRAPH_H
#include "graph.hpp"
#endif


void Graph::pickup(int spot, int passenger){
    vector<int> passengers_ = pickup_spots[spot].passengers;
    for (auto i = passengers_.begin() ; i != passengers_.end(); i++ ){
        if (*i == passenger){
            passengers_.erase(i);
            break;
        }
    }
    this->pickup_spots[spot].passengers = passengers_;
}

void Graph::print(){
    for (auto row : adjacency_matrix){
        for (auto element : row){
            cout << element << " ";
        }
        cout << endl;
    }

    cout << "Deliver spots : " << endl;
    for (deliver_spot ds : deliver_spots){
        cout << "Position : " << ds.position << ", Lastest finish: " << ds.lastest_finish << endl;
    }

    cout << "Pickup spots : " << endl;
    for (pickup_spot ps : pickup_spots){
        cout << "Position : " << ps.position << ", Passengers : ";
        for(int p : ps.passengers){
            cout << p << " ";
        }
        cout << ", Earliest start: " << ps.earlier_start << endl;
    }
}


