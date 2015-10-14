#include <iostream>
using namespace std;

class Solution {
    public:
        double myPow(double x, int n) {
            double res = 1;
            unsigned long long p;
            if (n<0) {
                p = -n;
                x = 1/x;
            } else {
                p = n;
            }

            while(p) {
                if (p&1) {
                    res *= x;
                }
                x *= x;
                p >>= 1;
            }
            return res;

        }
};

int main(void) {
    Solution sl;
    cout << sl.myPow(2,3);
}
