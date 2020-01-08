#include <vector>
using namespace std;

#define SPOT_H

typedef struct pickup_spot {
    int position; 
    int earlier_start;
    vector<int> passengers;
}pickup_spot;

typedef struct deliver_spot { 
    int position;
    int lastest_finish;
}deliver_spot;

