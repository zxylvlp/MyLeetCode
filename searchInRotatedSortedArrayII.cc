#include <vector>
#include <iostream>
using namespace std;
class Solution {
    public:
        bool search(vector<int>& nums, int target) {
            int l=0;
            int r=nums.size()-1;
            while(l<r) {
                int mid = (l+r)>>1;
                if (nums[mid]==target) {
                    return true;
                }
                if (nums[mid]<nums[r]) {
                    if (nums[mid]<target && nums[r]>=target)
                        l = mid + 1;
                    else
                        r = mid;
                } else if (nums[mid]>nums[r]) {
                    if (nums[mid]>target && nums[l]<=target)
                        r = mid;
                    else
                        l = mid + 1;

                } else {
                    r--;
                }
            }
            return nums[l] == target? true : false;
        }
};

int main(void) {
    Solution sl;
    vector<int> vec{1};
    cout << sl.search(vec, 0) << endl;
}
