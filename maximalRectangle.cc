#include <vector>
#include "printHelper.hh"
using namespace std;

class Solution {
    public:
        int maximalRectangle(vector<vector<char>>& matrix) {
            int m = matrix.size();
            if (m<=0)
                return 0;
            int n = matrix.back().size();
            vector<int> height(n, 0);
            vector<int> left(n, 0);
            vector<int> right(n, n);

            int maxArea = 0;
            for (int i=0; i<m; i++) {
                int curLeft = 0;
                int curRight = n;
                for (int j=0; j<n; j++) {
                    if (matrix[i][j]=='1') {
                        height[j] += 1;
                    } else {
                        height[j] = 0;
                    }
                }

                for (int j=0; j<n; j++) {
                    if (matrix[i][j]=='1') {
                        left[j] = max(left[j], curLeft);
                    } else {
                        left[j] = 0;
                        curLeft = j+1;
                    }
                }

                for (int j=n-1; j>=0; j--) {
                    if (matrix[i][j]=='1') {
                        right[j] = min(right[j], curRight);
                    } else {
                        right[j] = n;
                        curRight = j;
                    }
                }

                for (int j=0; j<n; j++) {
                    maxArea = max(maxArea, (right[j]-left[j])*height[j]);
                }
            }
            return maxArea;

        }
};

int main(void) {
    Solution sl;
    vector<vector<char>> mat {vector<char>{'0', '0', '0', '1', '0', '0', '0'},
        vector<char>{'0', '0', '1', '1', '1', '0', '0'},
        vector<char>{'0', '1', '1', '1', '1', '1', '0'}};
    cout << sl.maximalRectangle(mat) << endl;
}
