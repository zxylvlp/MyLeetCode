#include <iostream>
#include <vector>
#include "printHelper.hh"
using namespace std;
class Solution {

    public:

        vector<vector<int>> res;
        vector<int> row;
        int n;
        int k;
        vector<vector<int>> combine(int n_, int k_) {
            k = k_;
            n = n_;
            backtrack(0);
            return res;

        }

        void backtrack(int i) {
            if (row.size()==k) {
                res.push_back(row);
            } else if ((n-i)+row.size() < k) {
            } else {
                row.push_back(i+1);
                backtrack(i+1);
                row.pop_back();
                backtrack(i+1);
            }
        }

};

int main(void) {
    Solution sl;
    vector<vector<int>> res = sl.combine(4, 2);
    printMat(res);
}
