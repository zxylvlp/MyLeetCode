#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.size();
        vector<int> f(n, false);
        for (int i=0; i<n; i++) {
            for (int j=i; j<n; j++) {
                if (wordDict.find(s.substr(i,j-i+1))!=wordDict.end()&&f[i]) {
                    f[j] = true;
                    break;
                }
            }
        }
        return f[n-1];
        
    }
};
int main(void) {
    Solution sl;
}
