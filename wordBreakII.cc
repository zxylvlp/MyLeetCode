#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    unordered_map<string, vector<string>> m;

    vector<string> combine(string word, vector<string> prev) {
        for (int i=0; i<prev.size(); i++) {
            prev[i] += " " + word;
        }
        return prev;
    }

    vector<string> wordBreak(string s, unordered_set<string>& dict) {
        if (m.count(s))
            return m[s];
        vector<string> res;
        if (dict.count(s)) {
            res.push_back(s);
        }
        for (int i=1; i<s.size(); i++) {
            string word=s.substr(i);
            if (dict.count(word)) {
                string rem = s.substr(0, i);
                vector<string> prev = combine(word, wordBreak(rem, dict));
                res.insert(res.end(), prev.begin(), prev.end());
            }
        }
        m[s] = res;
        return res; 
    }
};
int main(void) {
    Solution sl;
    string str="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    unordered_set<string> dict{"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    sl.wordBreak(str, dict);
}
