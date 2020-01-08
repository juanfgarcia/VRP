#include <vector>
using namespace std;
#define VEHICLE_H

class Vehicle {
    // vector with the destiny of the passengers
    private:
        int position;
        vector<int> deliver_vector;    
        int capacity;

    public:
        //Constructor by parameter position and capacity
        Vehicle(int position_, int capacity_);

        // Deliver all passenger in the bus whose destiny is the actual position
        void deliver(int passenger);
        // Pickup a passenger
        void pickup(int passenger);
};

