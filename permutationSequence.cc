#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        string getPermutation(int n, int k) {
            k -= 1;
            string res(n, '0');
            int cnt = 1;
            for (int i=0; i<n; i++) {
                res[i] = '0' + i + 1;
                cnt *= (i+1);
            }

            if (k<0 || k>=cnt)
                return "";

            cnt /= n;
            int j;
            char tmp;
            for (int i=0; i<n-1; i++) {
                j = i + k/cnt;
                k = k%cnt;
                cnt /= (n-(i+1));
                if (j==i)
                    continue;
                tmp = res[i];
                res[i] = res[j];
                auto resBegin = res.begin();
                copy_backward(resBegin+i+1,resBegin+j, resBegin+j+1);
                res[i+1] = tmp;
            }

            return res;
        }
};

int main(void) {
    Solution sl;
    cout << sl.getPermutation(3, 3) << endl;

}
