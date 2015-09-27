#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		vector<int> searchRange(vector<int>& nums, int target) {
			vector<int> res(2, -1);
			int n = nums.size();
			int lo = 0, hi = n-1;
			while (lo<hi) {
				int mid = (lo + hi) / 2;
				if (nums[mid]<target)
					lo = mid + 1;
				else
					hi = mid;

			}
			if (nums[lo]!=target) 
				return res;
			res[0] = lo;
			hi = n-1;
			while (lo<hi) {
				int mid = (lo + hi) / 2 + 1;
				if (nums[mid]>target)
					hi = mid - 1;
				else
					lo = mid;
			}
			res[1] = lo;
			return res;

		}

};
void printVec(vector<int> vec) {
	cout << vec[0] << " " << vec[1] << endl;
}
int main() {
	Solution sl;
	vector<int> nums{5, 7, 7, 8, 8 ,10};
	vector<int> result = sl.searchRange(nums, 8);
	printVec(result);
}
