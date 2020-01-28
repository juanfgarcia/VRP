#include <algorithm>
#include <iostream>
using namespace std;

#ifndef VEHICLE_H
#include "vehicle.hpp"
#endif

void Vehicle::pickup(int passenger){
    if (this->deliver_vector.size()+1 <= this->capacity){
        this->deliver_vector.push_back(passenger);
    }
}
    
void Vehicle::deliver(int passenger){
    if (passenger == position){
        this->deliver_vector.erase(remove(this->deliver_vector.begin(), this-> deliver_vector.end(), passenger));
    }
}

void Vehicle::move(int stop){
    this->position = stop;
}

void Vehicle::print(){
    cout << "Vehicle position : " << this->position << endl;
    cout << "Vehicle passengers : [ " ;
    for (int passenger : this->deliver_vector){
        cout << passenger << " ";
    }
    cout << " ]" << endl;
}