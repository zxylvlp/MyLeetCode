#include <iostream>
#include <vector>
#include "interval.hh"
using namespace std;

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        auto it = intervals.begin();
        for(; it!=intervals.end(); it++) {
            if (it->end < newInterval.start) {
                res.push_back(*it);
            } else if (newInterval.end < it->start) {
                break;
            } else {
                newInterval.start = min(newInterval.start, it->start);
                newInterval.end = max(newInterval.end, it->end);
            }
        }
        res.push_back(newInterval);

        for(; it!=intervals.end(); it++) {
            res.push_back(*it);
        }
        return res;
        
    }
};

int main() {
    Solution sl;
    vector<Interval> vec{Interval(1,3), Interval(6,9)};
    Interval newInterval(2,5);
    vector<Interval> res = sl.insert(vec, newInterval);
    printVec(res);

}
