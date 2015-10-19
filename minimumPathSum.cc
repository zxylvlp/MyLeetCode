#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
class Solution {
    public:
        int minPathSum(vector<vector<int>>& grid) {
            int m = grid.size();
            if (m<1)
                return 0;
            int n = grid.front().size();
            if (n<1)
                return 0;
            vector<int> row(grid.front());
            partial_sum(row.begin(), row.end(), row.begin());

            for (int i=1; i<m; i++) {
                row[0] = row[0] + grid[i][0];
                for (int j=1; j<n; j++) {
                    row[j] = min(row[j-1], row[j]) + grid[i][j];
                }
            }
            return row[n-1];
        }
};

int main(void) {
    Solution sl;
    vector<vector<int>> vec{vector<int>{1,2}, vector<int>{1,1}};
    int res = sl.minPathSum(vec);
    cout << res << endl;
}

