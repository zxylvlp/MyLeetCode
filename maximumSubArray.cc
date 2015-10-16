#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int maxSubArray(vector<int> &nums) {
            int ans = nums[0];
            int sum = 0;
            for (int i=0; i<nums.size(); i++) {
                sum += nums[i];
                ans = max(sum, ans);
                sum = max(0, sum);
            }
            return ans;
        }
};

int main(void) {
    Solution sl;
    vector<int> vec{-2,1,-3,4,-1,2,1,-5,4};
    cout << sl.maxSubArray(vec) << endl;
}
