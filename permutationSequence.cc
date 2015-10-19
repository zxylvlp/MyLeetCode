#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
        string getPermutation(int n, int k) {
            string res(n, '0');
            int cnt = 1;
            for (int i=0; i<n; i++) {
                res[i] = '0' + i + 1;
                cnt *= (i+1);
            }

            if (k<1 || k>cnt)
                return "";
            cnt /= n;
            int j;
            char tmp;
            for (int i=0; i<n-1; i++) {
                j = k/cnt;
                k = k%cnt;
                cnt = cnt/(n-i);
                tmp = res[n-i];
                res[n-i] = res[j];
                for (int l=i; l<=j; l++) {
                    res[n-i] = res[n-i-1];
                }
                res[j] = tmp;
            }

            return res;
        }
};
