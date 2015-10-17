#include <vector>
#include "interval.hh"
using namespace std;

class Solution {

    public:
        static bool cmp(const Interval& a, const Interval& b) {
            return a.start < b.start;

        }
        vector<Interval> merge(vector<Interval>& intervals) {
            if (intervals.size() <= 1)
                return intervals;
            sort(intervals.begin(), intervals.end(), cmp);
            vector<Interval> res;
            res.push_back(intervals.front());
            for (int i = 1; i < intervals.size(); i++) {
                if (res.back().end >= intervals[i].start) {
                    if (res.back().end < intervals[i].end) {
                        res.back().end = intervals[i].end;
                    }
                } else {
                    res.push_back(intervals[i]);
                }
            }
            return res;
        }
};

int main() {
    Solution sl;
    vector<Interval> vec{Interval(1,3), Interval(2,6), 
     Interval(8,10), Interval(15,18)};
    printVec(vec);
    vector<Interval> res = sl.merge(vec);
    printVec(res);

}
