#include <algorithm>
using namespace std;

#ifndef VEHICLE_H
#include "vehicle.hpp"
#endif

Vehicle::Vehicle(int position_, int capacity_){
    this->position = position_;
    this->capacity = capacity_;
}

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
