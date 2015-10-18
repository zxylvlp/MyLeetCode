#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
        int uniquePaths(int m, int n) {
            if (n>m)
                return uniquePaths(n, m);
            vector<int> row(n, 1);
            for (int i=1; i<m; i++) {
                for (int j=1; j<n; j++) {
                    row[j] = row[j-1] + row[j];
                }
            }
            return row[n-1];
        }
};

int main(void) {
    Solution sl;
    int res = sl.uniquePaths(10, 10);
    cout << res << endl;
}

