#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
    public:
        string minWindow(string s, string t) {
            if (s.empty() || t.empty())
                return "";
            int count = t.size();
            int require[128] = {0};
            bool chSet[128] = {false};
            for (int i=0; i<count; i++) {
                require[t[i]]++;
                chSet[t[i]] = true;
            }
            int i = -1;
            int j = 0;
            int minLen = INT_MAX;
            int minIdx = 0;
            while (i<(int)s.size() && j<(int)s.size()) {
                if (count) {
                    i++;
                    require[s[i]]--;
                    if (chSet[s[i]] && require[s[i]]>=0)
                        count--;
                } else {
                    if (minLen > i - j + 1) {
                        minLen = i - j + 1;
                        minIdx = j;
                    }
                    require[s[j]]++;
                    if (chSet[s[j]] && require[s[j]]>0)
                        count++;
                    j++;
                }

            }
            if (minLen==INT_MAX)
                return "";
            return s.substr(minIdx, minLen);
        }
};

int main(void) {
    Solution sl;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << sl.minWindow(s, t) << endl;
}
