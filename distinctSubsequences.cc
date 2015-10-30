#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = t.size();
        int n = s.size();
        vector<vector<int>> f(m+1, vector<int>(n+1, 0));
        for (int i=0; i<n; i++)
            f[0][i] = 1;

        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                f[i][j] = f[i][j-1];
                if (t[i-1]==s[j-1])
                    f[i][j] += f[i-1][j-1];
            }
        }

        return f[m][n];
        
    }
};

int main(void) {
    Solution sl;
    cout << sl.numDistinct("rabbbit", "rabbit") << endl;
}
