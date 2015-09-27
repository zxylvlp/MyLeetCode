#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		int searchInsert(vector<int>& nums, int target) {
			int lo = 0, hi = nums.size() - 1;
			while(lo<=hi) {
				int mid = (lo + hi)/2;
				if (nums[mid]==target) {
					return mid;
				} else if (nums[mid]<target) {
					lo = mid + 1;
				} else {
					hi = mid - 1;
				}

			}
			return lo;

		}
};
int main() {

	Solution sl;
	vector<int> nums{1,3,5,6};
	cout << sl.searchInsert(nums,0) << endl;
}
