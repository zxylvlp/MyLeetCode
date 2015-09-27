#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		void nextPermutation(vector<int>& nums) {
			if (nums.empty()) return;
			int i;
			for (i=nums.size()-2; i>=0; i--) {
				if (nums[i]<nums[i+1]) break;
			}
			reverse(nums.begin()+i+1,nums.end());
			if (i==-1) return ;
			auto iter = upper_bound(nums.begin()+i+1,nums.end(),nums[i]);
			swap(nums[i],*iter);

		}
};
void printVec(vector<int> vec) {
	for(auto iter=vec.begin(); iter!=vec.end(); iter++)
		cout << *iter << " ";
	cout << endl;
}
int main() {
	Solution sl;
	vector<int> vec{1, 2, 3};
	printVec(vec);
	sl.nextPermutation(vec);
	printVec(vec);
}
