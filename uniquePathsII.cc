#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int>>& obGrid) {
            int m = obGrid.size();
            if (m<1) {
                return 0;
            }
            int n = obGrid.front().size();
            
            vector<int> row = obGrid.front();
            row[0] = !row[0];
            for (int i=1; i<row.size(); i++) {
                row[i] = row[i-1] && !row[i];
            }
            for (int i=1; i<m; i++) {
                for (int j=0; j<n; j++) {
                    if (obGrid[i][j]!=1) {
                        if (j>0)
                            row[j] = row[j-1] + row[j];
                    } else {
                        row[j] = 0;
                    }
                }
            }
            return row[n-1];
        }
};

int main(void) {
    Solution sl;
}

