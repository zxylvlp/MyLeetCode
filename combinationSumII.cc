#include <iostream>
#include <vector>
using namespace std;
class Solution {


	public:
		vector<vector<int>> combinationSum2(vector<int>& candidates_, int target_) {
			candidates = candidates_;
			sort(candidates.begin(), candidates.end());
			target = target_;
			cddSize = candidates.size();
			result = vector<vector<int>>();
			backtrack(0);
			return result;
		}
		
	private:
		void backtrack(int i) {
				if (i>=cddSize)
					return ;
				if (target>candidates[i]) {


					target -= candidates[i];
					tmp.push_back(candidates[i]);
					if (testRightOrder()) {
						backtrack((i+1));
					}
					tmp.pop_back();
					target += candidates[i];

					backtrack((i+1));
					
				} else if (target==candidates[i]) {

					tmp.push_back(target);
					if (testRightOrder()) {
						result.push_back(tmp);
					}
					tmp.pop_back();
				} 
		}
		bool testRightOrder() {
			if (result.empty()) return true;
			vector<int> back = result.back();
			int n = min(tmp.size(), back.size());
			for (int i=0; i<n; i++) {
				if (back[i]<tmp[i])
					return true;
				else if (back[i]==tmp[i])
					continue;
				else
					return false;

			}

			return false;
		}

		vector<int> candidates;
		int cddSize;
		int target;
		vector<int> tmp;
		vector<vector<int>> result;
};
int main() {
	Solution sl;

	vector<int> vec{10,1,2,7,6,1,5};
	vector<vector<int>> result = sl.combinationSum2(vec, 8);
	for (auto iter=result.begin(); iter!=result.end(); iter++) {
		for (auto iter1=(*iter).begin(); iter1!=(*iter).end(); iter1++) {
			cout << *iter1 << " ";
		}
		cout << endl;
	}
}
