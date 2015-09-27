#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		int jump(vector<int>& nums) {
			int n = nums.size();
			if (n<=1) return 0;
			int maxReachPos = nums[0];
			int curMaxReachPos = nums[0];
			int curStep = 1;
			
			for (int i=1; i<= maxReachPos; i++) {
				curMaxReachPos = max(curMaxReachPos, i+nums[i]);
				if (i==n-1) {
					return curStep;
				}
				if (i==maxReachPos) {
					maxReachPos = curMaxReachPos;
					curStep++;
				}

			}
			return 0;
		}

};

int main() {

	vector<int> vec{2, 3, 1, 1, 4};
	Solution sl;
	cout << sl.jump(vec) << endl;

}
