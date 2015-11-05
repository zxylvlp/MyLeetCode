#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        if (n<=1)
            return 0;
        vector<vector<bool>> isp(n, vector<bool>(n, false));
        vector<int> res(n, n-1);
        for (int i=0; i<s.size(); i++) {
            for (int left=0; left<=i; left++) {
                if (s[left]==s[i]&&(left+1>=i||isp[left+1][i-1])) {
                    isp[left][i] = true;
                    if (left)
                        res[i] = min(res[i], res[left-1]+1);
                    else
                        res[i] = min(res[i], 0);
                }
            }
        }
        return res[n-1];
    }
};
int main(void) {
    Solution sl;
}
