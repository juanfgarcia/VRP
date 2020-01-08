#include <fstream>
#include <sstream>
#include <iterator>
#include <iostream>
#ifndef GRAPH_H
#include "graph.hpp"
#endif

Graph::Graph(string input_file){
    ifstream myfile (input_file);
    string line;

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
            adjacency_matrix.push_back(aux);
        }

        // Create deliver spots vector
        for (int i = 0; i<nod; i++){
            getline(myfile, line);
            istringstream iss(line);
            vector<string> data((istream_iterator<string>(iss)),
                                istream_iterator<string>());

            deliver_spot ds = {stoi(data[0]), stoi(data[1])};
            this->deliver_spots.push_back(ds);
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
            
            pickup_spots.push_back(ps);
        }

        getline(myfile, line);
        iss = istringstream(line);
        vector<string> data((istream_iterator<string>(iss)),
                    istream_iterator<string>());
        
        this->initial.push_back(stoi(data[0]));
        this->initial.push_back(stoi(data[1]));
    }else throw(404);
}

vector<int> Graph::getInitial(){
    return initial;
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