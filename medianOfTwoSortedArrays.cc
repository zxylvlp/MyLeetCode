#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
	private:
		int getKth(int nums1[], int m, int nums2[], int n, int k){
			if (m > n)
				return getKth(nums2, n, nums1, m, k);
			if (m == 0)
				return nums2[k-1];
			if (k == 1)
				return min(nums1[0], nums2[0]);
			int i = min(k/2,m);
			int j = k/2;
			if (nums1[i-1] > nums2[j-1]) {
				return getKth(nums1, m, nums2+j, n-j, k-j);
			} else {
				return getKth(nums1+i, m-i, nums2, n, k-i);
			}
		}
	public:
		double findMedianSortedArrays(vector<int> nums1, vector<int>nums2) {
			int m = nums1.size();	
			int n = nums2.size();
			int k = (m+n+1) >> 1;
			if ((m+n)&1)
				return getKth(&nums1[0], m, &nums2[0], n, k);
			else
				return (getKth(&nums1[0], m, &nums2[0], n,k) + (getKth(&nums1[0], m, &nums2[0], n, k+1)))/2.0;
		}
};
int main() {
	Solution solution;
	vector<int> nums1{1,3,5,7,9};
	vector<int> nums2{2,4,6,8,10};
	double result = solution.findMedianSortedArrays(nums1, nums2);
	cout<<result<<endl;
}
