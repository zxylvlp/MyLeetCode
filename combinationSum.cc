#include <iostream>
#include <vector>
using namespace std;
class Solution {

	public:
		vector<vector<int>> combinationSum(vector<int>& candidates_, int target_) {
			target = target_;
			candidates = candidates_;
			sort(candidates.begin(),candidates.end());
			cddSize = candidates.size();
			result = vector<vector<int>>();
			backtrack(0);
			return result;
		}
	private:
		void backtrack(int i) {
			for (; i<cddSize; i++) {
				if (target-candidates[i]>0) {
					tmp.push_back(candidates[i]);
					target -= candidates[i];
					backtrack(i);
					tmp.pop_back();
					target += candidates[i];
				} else if (target-candidates[i]==0){
					tmp.push_back(target);
					result.push_back(tmp);
					tmp.pop_back();
					break;
				} else {
					break;
				}

			}

		}

		vector<int> tmp;
		vector<vector<int>> result;
		vector<int> candidates;
		int target;
		int cddSize;
};
int main() {

}
