#include <iostream>
#include <string>
using namespace std;
class Solution {
	public:
		string preProcess(string s) {
			int n = s.length();
			if (n == 0)
				return "^$";
			int base = 2*n;
			char* result = new char[base+4];
			result[0] = '^';
			result[base+1] = '#';
			result[base+2] = '$';
			result[base+3] = '\0';
			for (int i=0; i<n; i++) {
				int base = 2*i;
				result[base+1] = '#';
				result[base+2] = s[i];
			}
			string ret = string(result);
			delete[] result;
			return ret;


		}
		string longestPalindrome(string s) {
			string afterS = preProcess(s);
			int n = afterS.length();
			int R=0, C=0;
			int* P= new int[n];
			int maxLen = 0;
			int centerIndex = 0;
			int iMirror;
			for (int i=1 ; i<n-1; i++) {
				iMirror = 2*C - i;
				P[i] = (R>i)? min(P[iMirror], R-i): 0;
				while (afterS[ i+P[i]+1 ] == afterS[ i-P[i]-1 ]) P[i]++;

				if (i+P[i] > R) {
					R = i+P[i];
					C = i;
				}

				if (P[i]>maxLen) {
					maxLen = P[i];
					centerIndex = i;
				}
			}
			delete[] P;
			return s.substr((centerIndex-1-maxLen)/2,maxLen);
		}
};

int main() {
	Solution solution;
	string s = "babcbabcbaccba";
	string result = solution.longestPalindrome(s);
	cout << s << endl << result << endl;
}
