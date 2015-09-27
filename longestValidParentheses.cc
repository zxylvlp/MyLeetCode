#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		int longestValidParentheses(string s) {
			s = ")" + s;
			int n = s.length();
			vector<int> longest(n,0);
			int res = 0;
			for (int i=1; i < n; i++) {
				if (s[i]=='(')
					longest[i] = 0;
				else {
					if (s[i-1]=='(') {
						longest[i] = longest[i-2] + 2;
						res = max(res, longest[i]);
					} else {
						if (s[i-longest[i-1]-1]=='(') {
							longest[i] = longest[i-longest[i-1]-2] + longest[i-1] + 2;
							res = max(res, longest[i]);
						} 
					}
				}

			}

			return res;
		}
};
int main() {
	Solution sl;
	cout << sl.longestValidParentheses(")()())") << endl;

}
