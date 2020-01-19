#include <vector>
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
    public:
        vector<vector<int>> adjacency_matrix;
        vector<deliver_spot> deliver_spots;
        vector<pickup_spot> pickup_spots;
        
        // Default constructor
        Graph(){};
        // Default destructor
        ~Graph(){};
        void print();
};