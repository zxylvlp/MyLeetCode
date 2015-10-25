#include <iostream>
#include <string>
using namespace std;

class Solution {
    public:
        bool isScramble(string s1, string s2) {
            int sLen = s1.size();
            if (sLen==0) return true;
            if (sLen==1) return s1==s2;
            bool isS[sLen+1][sLen][sLen];

            for (int i=0; i<sLen; i++) {
                for (int j=0; j<sLen; j++) {
                    isS[1][i][j] = s1[i] == s2[j];
                }
            }

            for (int k=2; k<=sLen; k++) {
                for (int i=0; i<=sLen-k; i++) {
                    for (int j=0; j<=sLen-k; j++) {
                        isS[k][i][j] = false;
                        for (int l=1; l<k && !isS[k][i][j]; l++) {
                            isS[k][i][j] = isS[k][i][j] || (isS[l][i][j] && isS[k-l][i+l][j+l]);
                            isS[k][i][j] = isS[k][i][j] || (isS[l][i+k-l][j] && isS[k-l][i][j+l]);

                        }

                    }
                }
            }
            return isS[sLen][0][0];

        }
};

int main(void) {
    Solution sl;
    cout << sl.isScramble("rgtae", "great") << endl;
}
