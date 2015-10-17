#include <vector>
#include <iostream>
using namespace std;
/**
 * Definition for an interval.
 */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

void printVec(vector<Interval>& vec) {
    for (int i=0; i<vec.size(); i++) {
        cout << vec[i].start << " " << vec[i].end << endl;
    }
    cout << endl;
}

