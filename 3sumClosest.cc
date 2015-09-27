#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
	public:
		int threeSumClosest(vector<int>& nums, int target) {

			sort(nums.begin(), nums.end());
			int n = nums.size();
			if (n <= 3) {
				return accumulate(nums.begin(), nums.end(), 0);
			}

			int ans=nums[0] + nums[1] + nums[2];
			int sum;
			for (int i=0; i<=n-3; i++) {
				int front = i+1;
				int back = n-1;
				while(front<back) {
					sum = nums[i] + nums[front] + nums[back];
					
					if (abs(ans-target)>abs(sum-target)) {
						ans = sum;
					}
					sum>target?back--:front++;
				}
			}

			return ans;
		}
};
int main() {
	vector<int> s{-1, 2, 1, 4};
	int target = 1;
	Solution sl;
	int res = sl.threeSumClosest(s,target);
	cout << res << endl;
}
