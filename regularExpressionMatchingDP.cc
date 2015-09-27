#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		bool isMatch(string s, string p) {
			int m = s.length(), n = p.length();
			vector<vector<bool>> mat(m+1, vector<bool>(n+1, false));
			//代表空串[0,-1]
			//代表一个字符的字符串[0,0]
			//[0][0]代表空串[0,-1]和空串[0,-1]之间的匹配程度
			mat[0][0] = true;
			for (int i=1; i <= m; i++) 
				mat[i][0] = false;
			for (int i=1; i <= n; i++)
				mat[0][i] = i>1 && p[i-1]=='*' && mat[0][i-2];
			for (int i=1; i<=m; i++) {
				for (int j=1; j<=n; j++){
					if (p[j-1]=='*')
						mat[i][j] = mat[i][j-2] || ((s[i-1]==p[j-2]||p[j-2]=='.') && mat[i-1][j]);
					else
						mat[i][j] = mat[i-1][j-1] && (s[i-1]==p[j-1]||p[j-1]=='.');
				}
			}
			return mat[m][n];
		}
};
int main() {
	Solution solution;
	string s = "aab";
	string p = "c*a*b";
	bool result = solution.isMatch(s, p);
	cout<<result<<endl;
}

