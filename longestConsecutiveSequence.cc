#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_map<int,int> map;
        for (int i=0; i<nums.size(); i++) {
            if (!map.count(nums[i])) {
                int left = map.count(nums[i]-1) ? map[nums[i]-1] : 0;
                int right = map.count(nums[i]+1) ? map[nums[i]+1] : 0;
                int sum = left + right + 1;
                map[nums[i]] = sum;
                res = max(res, sum);
                map[nums[i]-left] = sum;
                map[nums[i]+right] = sum;
            }
        }
        return res;
        
    }
};
int main(void) {
    Solution sl;
}
