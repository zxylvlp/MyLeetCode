#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		int trap(vector<int>& height) {
			int n = height.size();
			int left = 0, right = n-1;
			int maxLeft = 0, maxRight = 0;
			int res = 0;
			while(left<right) {
				if (height[left]<=height[right]) {
					if (maxLeft<=height[left]) {
						maxLeft = height[left];
					} else {
						res += (maxLeft - height[left]);
					}
					left++;
				} else {
					if (maxRight<=height[right]) {
						maxRight = height[right];
					} else {
						res += (maxRight - height[right]);
					}
					right--;
				}
			}
			return res;
		}
};
int main() {
	Solution sl;
	vector<int> vec{0,1,0,2,1,0,1,3,2,1,2,1};
	cout << sl.trap(vec) << endl;


}
