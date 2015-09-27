#include <iostream>
using namespace std;
class Solution {
	private:
		bool matchFirstChar(string& s, string& p) {
			if (s.empty()||p.empty())
				return false;
			if (s[0]==p[0] || p[0]=='.')
				return true;
			return false;

		}
	public:
		bool isMatch(string s, string p) {
			if (s.empty() && p.empty())
				return true;
			if (p.length()>1 && p[1]=='*') {
					return isMatch(s, p.substr(2))||(matchFirstChar(s, p) && isMatch(s.substr(1),p));
			} else {
					return matchFirstChar(s, p) && isMatch(s.substr(1),p.substr(1));
			}
		}
};
int main() {
	Solution solution;
	string s = "aab";
	string p = "c*a*b";
	bool result = solution.isMatch(s, p);
	cout<<result<<endl;
}

