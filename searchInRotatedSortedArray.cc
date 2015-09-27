#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		int search(vector<int>& nums, int target) {
			int n = nums.size();
			int lo=0, hi=n-1;
			while (lo<hi) {
				int mid = (lo+hi)>>1;
				if (nums[mid]>nums[hi]) {
					lo = mid+1;
				} else {
					hi = mid;

				}
			}
			int rot = lo;
			lo = 0;
			hi = n-1;
			while(lo<=hi) {
				int mid = (lo+hi)>>1;
				int realMid = (mid+rot)%n;
				if (nums[realMid]==target) {
					return realMid;
				} else if (nums[realMid]>target) {
					hi = mid - 1;
				} else {
					lo = mid + 1;
				}
			}
			return -1;
		}

};
int main() {
	Solution sl;
	vector<int> vec;
	cout << sl.search(vec, 4) << endl;

}
