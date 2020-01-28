#include <fstream>
#include <sstream>
#include <iterator>
#include <iostream>
using namespace std;

#ifndef STATE_H
#include "state.hpp"
#endif

State::State(string input_file){
    ifstream myfile (input_file);
    string line;

    Graph* new_graph = new Graph();
    Vehicle* new_vehicle = new Vehicle();
    
    if (myfile.is_open()){
        // Get number of stops, deliver spots and pickup spots
        getline(myfile, line);
        istringstream iss(line);
            vector<string> numbers((istream_iterator<string>(iss)),
                                istream_iterator<string>());
        
        int nos = stoi(numbers[0]); // Number of stops
        int nod = stoi(numbers[1]); // Number of deliver spots
        int nop = stoi(numbers[2]); // Number of pickup spots
        
        // Create adjacency matrix
        for (int i = 0; i< nos; i++){
            getline(myfile, line);
            istringstream iss(line);
            vector<string> vertexs((istream_iterator<string>(iss)),
                                istream_iterator<string>());
            vector<int> aux;
            for (auto vertex : vertexs){
                if (vertex == "--"){
                    aux.push_back(-1);
                }else{
                    aux.push_back(stoi(vertex));
                }
            }
            new_graph->adjacency_matrix.push_back(aux);
        }

        // Create deliver spots vector
        for (int i = 0; i<nod; i++){
            getline(myfile, line);
            istringstream iss(line);
            vector<string> data((istream_iterator<string>(iss)),
                                istream_iterator<string>());

            deliver_spot ds = {stoi(data[0]), stoi(data[1])};
            new_graph->deliver_spots.push_back(ds);
        }

        // Create pickup spots vector
        for (int i = 0; i<nop; i++){
            getline(myfile, line);
            istringstream iss(line);
            vector<string> data((istream_iterator<string>(iss)),
                                istream_iterator<string>());
            pickup_spot ps;
            ps.position = stoi(data[0]);
            for (int j = 0; j < stoi(data[1]); j++){
                ps.passengers.push_back(stoi(data[j+2]));
            }
            ps.earlier_start = stoi(data[data.size()-1]);
            
            new_graph->pickup_spots.push_back(ps);
        }

        getline(myfile, line);
        iss = istringstream(line);
        vector<string> data((istream_iterator<string>(iss)),
                    istream_iterator<string>());

        new_vehicle->position = stoi(data[0]);
        new_vehicle->capacity = stoi(data[1]);

        this->graph = *new_graph;
        this->vehicle = *new_vehicle;
        this->parent = nullptr;
    }
}

vector<State*> State::deliver(){
    vector<State*> successors;
    for (unsigned int i = 0; i< this->graph.deliver_spots.size(); i++){
        if (this->vehicle.position == graph.deliver_spots[i].position){
            for (int passenger : this->vehicle.deliver_vector){
                if (passenger == graph.deliver_spots[i].position){
                    State *child = new State(*this);
                    child->vehicle.deliver(passenger);
                    child->setParent(this);
                    successors.push_back(parent);
                }   
            }
        }
    }
    return successors;
}

vector<State*> State::pickup(){
    vector<State*> successors;
    for (unsigned int i = 0; i<this->graph.pickup_spots.size(); i++){
        if (this->vehicle.position == graph.pickup_spots[i].position){
            for (int passenger : graph.pickup_spots[i].passengers){
                State *child = new State(*this);
                child->graph.pickup(i, passenger);
                child->vehicle.pickup(passenger);
                child->setParent(this);
                successors.push_back(child);
            }
        }
    }
    return successors;
}

vector<State*> State::move(){
    vector<State*> successors;
    for (unsigned int vertex = 0; vertex < graph.adjacency_matrix[vehicle.position].size(); vertex++){
        if ( graph.adjacency_matrix[vehicle.position][vertex] != -1 ){
            State *child = new State(*this);
            child->vehicle.move(vertex);
            child->setParent(this);   
            successors.push_back(child);
        }
    }
    return successors;
}

vector<State*> State::getSuccessors(){
    vector<State*> successors;
    for (State *state: this->move()){
        successors.push_back(state);
    }
    for (State *state: this->pickup()){
        successors.push_back(state);
    }
    for (State *state: this->deliver()){
        successors.push_back(state);
    }
    return successors;
}

void State::print(){
    this->graph.print();
    this->vehicle.print();
}
