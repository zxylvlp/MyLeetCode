#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		int removeElement(vector<int>& nums, int val) {
			int n = nums.size();
			int i1 = 0, i2 = 0;
			for(; i2<n ;i2++) {
				if (nums[i2]!=val) {
					nums[i1] = nums[i2];
					i1++;
				}
			}
			return i1+1;
		}
};
int main() {
	//vector<int> nums{3, 5, 1, 2, 4, 3, 5};
	vector<int> nums;
	Solution sl;
	int newLength = sl.removeElement(nums, 3);
	cout << newLength<<endl;


}
