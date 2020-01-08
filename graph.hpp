#include <vector>
#include <string>
using namespace std;

typedef struct pickup_spot {
    int position; 
    int earlier_start;
    vector<int> passengers;
}pickup_spot;

typedef struct deliver_spot { 
    int position;
    int lastest_finish;
}deliver_spot;

#define GRAPH_H

class Graph {
    private:
        vector<vector<int>> adjacency_matrix;
        vector<deliver_spot> deliver_spots;
        vector<pickup_spot> pickup_spots;
        // Vector for initial_position and capacity of the vehicle
        vector<int> initial;
    public:

        // Default constructor
        Graph(){};
        //Constructor given an input file
        Graph(string input_file);


        vector<int> getInitial();
        void print();
};