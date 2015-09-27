#include <iostream>
#include <vector>
using namespace std;
class Solution {

    public:
        void permuteRecursize(int begin) {
            if (begin==nums.size()-1)
                result.push_back(nums);
            for (int i=begin; i<nums.size(); i++) {
                swap(nums[begin], nums[i]);
                permuteRecursize(begin+1);
                swap(nums[begin], nums[i]);
            }
        }
        vector<vector<int>> result;
        vector<int> nums;
        vector<vector<int>> permute(vector<int>& nums_) {
            nums = nums_;
            permuteRecursize(0);
            return result;
        }
};

int main(void) {
    vector<int> vec{1,2,3,4,5};
    Solution s;
    vector<vector<int>> res = s.permute(vec);
    cout << res.size() << endl;
    for (int i=0; i< res.size(); i++) {
        for (int j=0; j< res[i].size(); j++) {
            cout << res[i][j];
        }
        cout << endl;
    }

}
