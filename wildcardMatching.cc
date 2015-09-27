#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		bool isMatch(string s_, string p_) {

			const char *star = nullptr;

			const char *s = s_.c_str(), *ss = s_.c_str();
			const char *p = p_.c_str();

			while (*s) {
				if ((*s==*p&&*p!='*') || *p=='?') {
					s++;
					p++;
					continue;
				}
				if (*p=='*') {
					star = p++;
					ss = s;
					continue;
				}
				if (star) {
					p = star + 1;
					s = ++ss;
					continue;
				}
				return false;
			}

			while (*p=='*') {p++;}
			return !*p;
		}
};

int main() {

	Solution sl;
	cout << sl.isMatch("aa", "a*") << endl;

}
