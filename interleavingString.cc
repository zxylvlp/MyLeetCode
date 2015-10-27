#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    public:
        bool isInterleave(string s1, string s2, string s3) {
            int l = s1.size();
            int m = s2.size();
            int n = s3.size();
            if (n!=l+m)
                return false;

            vector<bool> t(m+1, false);
            t[0] = true;
            for (int i=1; i<m+1; i++) {
                t[i] = (s2[i-1] == s3[i-1]);
            }
            for (int i=1; i<l+1; i++) {
                t[0] = t[0] && (s1[i-1] == s3[i-1]);
                for (int j=1; j<m+1; j++) {
                    t[j] = t[j] && (s1[i-1] == s3[i+j-1]);
                    t[j] = t[j] || (t[j-1] && (s2[j-1] == s3[i+j-1]));
                }
            }
            return t[m];
            
        }
};

int main(void) {
    Solution sl;
    cout << sl.isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
}
