#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;
    vector<vector<string>> partition(string s) {
        int n = s.size();
        if (n==0)
            return res;
        backtrack(0, s);
        return res;
    }
    void backtrack(int i, string &s) {
        if (i==s.size()) {
            res.push_back(path);
        }
        for (int j=i; j<s.size(); j++) {
            if (isPalindrome(s, i, j)) {
                path.push_back(s.substr(i, j-i+1));
                backtrack(j+1, s);
                path.pop_back();
            }

        }
    }

    bool isPalindrome(string &s, int start, int end) {
        while(start<end) {
            if (s[start++]!=s[end--])
                return false;
        }
        return true;
    }
};
int main(void) {
    Solution sl;
}
