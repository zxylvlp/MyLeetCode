#include <iostream>
using namespace std;
class Solution {
    public:
        int uniquePaths(int m, int n) {
            if (m>n)
                return uniquePaths(n, m);
            int all = m + n - 2;
            int k = m - 1;
            int down = 1;
            long long up = 1;

            for(int i=1; i<=k; i++) {
                down *= i;
                up *= (all-i+1);
                cout << "up : " << up << endl;
                cout << "down : " << down << endl;
            }
            return up/down;
        }
};

int main(void) {
    Solution sl;
    int res = sl.uniquePaths(10, 10);
    cout << res << endl;
}
