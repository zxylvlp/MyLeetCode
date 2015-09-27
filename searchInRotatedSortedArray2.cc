#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		int search(vector<int>& nums, int target) {
			int n = nums.size();
			if (n==0) return -1;
			int lo=0, hi=n-1;
			while (lo<hi) {
				int mid = (lo+hi)>>1;
				if (nums[mid]==target) return mid;
				if (nums[lo]<=nums[mid]) {
					if (nums[lo]<=target&&nums[mid]>target) {
						hi = mid - 1;
					} else {
						lo = mid + 1;
					}
				} else {
					if (nums[mid]<target&&nums[hi]>=target) {
						lo = mid + 1;

					} else {
						hi = mid - 1;

					}

				}
			}
			if (nums[lo]==target) return lo;
			else return -1;

		}

};
int main() {
	Solution sl;
	vector<int> vec;
	cout << sl.search(vec, 4) << endl;

}
