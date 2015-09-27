#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			//Key is the number and value is its index in the vector
			unordered_map<int, int> hash;
			vector<int> result;
			for (int i = 0; i < nums.size(); i++) {
				int numToFind = target - nums[i];
				// if numToFind is found in map, return them
				if (hash.find(numToFind)!=hash.end()) {
					//+1 because indices are NOT zero based
					result.push_back(hash[numToFind]+1);
					result.push_back(i+1);
					return result;
				}
				hash[nums[i]] = i;
			}
			return result;
		}
};
int main(void) {
	vector<int> numbers{2, 7, 11, 15};
	int target = 9;
	Solution* solution = new Solution;
	vector<int> result = solution->twoSum(numbers, target);
	cout<<result[0]<<','<<result[1];
	delete solution;
}
