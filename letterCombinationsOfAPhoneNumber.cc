#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
	private:
		vector<string> table{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
		vector<string> result;
		string local;
		string nums;
		int n;

	public:
		vector<string> letterCombinations(string digits) {
			nums = digits;
			n = nums.length()-1;
			backtrack(0);
			return result;
		}

		void backtrack(int l) {
			if (l>n) {
				if (local.length()>0)
					result.push_back(local);
			} else {
				int num = nums[l]-'0';
				string tbItem = table[num];
				for(string::iterator iter=tbItem.begin(); iter!=tbItem.end(); iter++) {
					local.push_back(*iter);
					backtrack(l+1);
					local.pop_back();
				}
			}
		}

};
void printVec(vector<string> vec) {
	for(vector<string>::iterator iter=vec.begin(); iter!=vec.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl;
}
int main() {
	Solution sl;
	vector<string> ret = sl.letterCombinations("23");
	printVec(ret);

}
