#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
	public:
		vector<vector<int>> fourSum(vector<int>& nums, int target) {
			vector<vector<int>> result;
			int n = nums.size();
			if (n < 4) return result;
			sort(nums.begin(), nums.end());
			
			unordered_map<int, vector<pair<int, int>>> hash;
			
			for(int i=2; i<n-1; i++) {
				for(int j=i+1; j<n; j++) {
					hash[nums[i]+nums[j]].push_back(make_pair(i,j));
				}
			}

			for(int i=0; i<n-3; i++) {
				if (i>0 && nums[i]==nums[i-1]) continue;
				for(int j=i+1; j<n-2;j++) {
					if (j>i+1 && nums[j]==nums[j-1]) continue;
					int need = target-nums[i]-nums[j];
					if(hash.count(need)<=0)
						continue;
					vector<pair<int, int>> vec = hash[need];
					for(auto it = vec.begin(); it!=vec.end(); it++) {
						int k = it->first;
						int l = it->second;
						if (j>=k)
							continue;
						if(!result.empty()) {
							vector<int>  back= result.back();
							if (back[0]==nums[i] && 
									back[1] == nums[j] &&
									back[2] == nums[k] && 
									back[3] == nums[l])
								continue;
						}
						vector<int> back{nums[i], nums[j], nums[k], nums[l]};
						result.push_back(back);
					}

				}
			}
			return result;
		}
};
void printVec(vector<int>& vec) {
	for(vector<int>::iterator iter=vec.begin(); iter!=vec.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl;
}
void printMat(vector<vector<int>>& mat) {
	for(vector<vector<int>>::iterator iter=mat.begin(); iter!=mat.end(); iter++) {
		printVec(*iter);
	}
}
int main() {
	vector<int> s{1, 0, -1, 0, -2, 2};
	int target = 0;
	Solution sl;
	vector<vector<int>> res = sl.fourSum(s,target);
	printMat(res);
}
