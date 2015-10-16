#include <vector>
#include <iostream>
using namespace std;

class Solution {
    public:
        bool canJump(vector<int>& nums) {
            if (nums.size()<=1) {
                return true;
            }
            int step = nums[0];
            int i = 0;
            while(step && i!=nums.size()-1) {
                step = max(nums[i], step-1);
                i++;
            }
            if (step>0)
                return true;
            return false;
        }
};

int main(void) {
    Solution sl;
    vector<int> nums{3,2,1,0,4};
    cout << sl.canJump(nums) << endl;
}
