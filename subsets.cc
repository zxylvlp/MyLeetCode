#include <iostream>
#include <vector>
#include <algorithm>
#include "printHelper.hh"
using namespace std;
class Solution {

    public:

        vector<vector<int>> res;
        vector<int> row;
        vector<int> nums;
        int n;
        vector<vector<int>> subsets(vector<int>& nums_) {
            nums = nums_;
            sort(nums.begin(), nums.end());
            n = nums.size();
            backtrack(0);
            return res;
        }

        void backtrack(int i) {
            if (i==n) {
                res.push_back(row);
            } else {
                row.push_back(nums[i]);
                backtrack(i+1);
                row.pop_back();
                backtrack(i+1);
            }
        }
};

int main(void) {
    Solution sl;
    vector<int> nums{1,2,3};
    vector<vector<int>> res = sl.subsets(nums);
    printMat(res);
}
