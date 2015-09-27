#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			int longest = 0;
			int m = 0;
			vector<int> charIndex(256, -1);
			for(int i=0; i<s.length(); i++) {
				m = max(charIndex[s[i]] + 1, m);
				charIndex[s[i]] = i;
				longest = max(longest, i - m + 1);
			}
			return longest;
		}
};
int main(void) {
	string s = "abcabcbb";
	Solution* solution = new Solution;
	int result = solution->lengthOfLongestSubstring(s);
	cout<<result<<endl;
	delete solution;
}
