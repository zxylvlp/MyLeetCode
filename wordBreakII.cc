#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> res;
        if (s=="") {
            res.push_back("");
            return res;
        }
        int maxL = 0;
        for (auto it=wordDict.begin(); it!=wordDict.end(); it++) {
            maxL = max(maxL, int(it->size()));
        }
        vector<vector<bool>> mat(s,vecotr<bool>(s.size(), false));
        for (int i=0; i<s.size(); i++) {
            for (int j=i; j<s.size(); j++) {
                if (wordDict.find(s.substr(i,j-i+1))!=wordDict.end()) {
                    mat[i][j] = true;
                }
            }
        }
        res = wordBreakRe(s, wordDict, maxL, mat);
        return res; 
    }

    vector<string> wordBreakRe(string s, unordered_set<string>& wordDict, int maxL, vecot<vector<bool>> &mat) {
        vector<string> res;
        int n = min(maxL, int(s.size()));
        for (int i=1; i<=n; i++) {
            string prefix = s.substr(0, i);
            if (find(prefix)!=wordDict.end()) {
                if (i==s.size()) {
                    res.push_back(prefix);
                    return res;
                }
                auto res_ = wordBreakRe(s.substr(i), wordDict, maxL);
                for (int j=0; j<res_.size(); j++) {
                    res.push_back(prefix + " " + res_[j]);
                }
            }
        }
        return res; 
    }

};
int main(void) {
    Solution sl;
    string str="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    unordered_set<string> dict{"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    sl.wordBreak(str, dict);
}
