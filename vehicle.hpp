#include <vector>
using namespace std;
#define VEHICLE_H

class Vehicle {
    public:
        int position;
        vector<int> deliver_vector;    
        unsigned int capacity;

        Vehicle(){};
        ~Vehicle(){};

        // Deliver all passenger in the bus whose destiny is the actual position
        void deliver(int passenger);
        // Pickup a passenger
        void pickup(int passenger);
        // Move to 'stop'
        void move(int stop);

        void print();
};

