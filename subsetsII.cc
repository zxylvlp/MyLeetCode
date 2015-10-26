#include <vector>
#include "printHelper.hh"
class Solution {
    public:
        vector<vector<int>> res;
        vector<int> nums;
        vector<int> row;
        int n;
        vector<vector<int>> subsetsWithDup(vector<int>& nums_) {
            nums = nums_;
            sort(nums.begin(), nums.end());
            n = nums_.size();
            backtrack(0);
            return res;
        }

        void backtrack(int i) {
            if (i==n) {
                res.push_back(row);
                return;
            }
            
            int j = i;
            while(j<n-1 && nums[j] == nums[j+1]) {
                j++;
            }
            backtrack(j+1);
            for (int k=i; k<=j; k++) {
                row.push_back(nums[i]);
                backtrack(j+1);
            }
            for (int k=i; k<=j; k++) {
                row.pop_back();
            }
        }
};

int main(void) {
    Solution sl;
    vector<int> vec{1,2,2};
    auto res = sl.subsetsWithDup(vec);
    printMat(res);
}

