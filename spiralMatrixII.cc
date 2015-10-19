#include <vector>
#include "printHelper.hh"
using namespace std;

class Solution {
    public:
        vector<vector<int>> generateMatrix(int n) {
            if (n<1)
                return vector<vector<int>>();
            vector<int> row(n, 0);
            vector<vector<int>> matrix(n, row);
            int now = 1;
            int rEnd = matrix.size()-1;
            int cEnd = matrix[0].size()-1;
            int rStart = 0;
            int cStart = 0;
            while (rStart<=rEnd && cStart<=cEnd) {
                for (int i=cStart; i<=cEnd; i++) {
                    matrix[rStart][i] = now;
                    now++;
                }
                rStart++;
                for (int i=rStart; i<=rEnd; i++) {
                    matrix[i][cEnd] = now;
                    now++;
                }
                cEnd--;
                if (rStart<=rEnd) {
                    for(int i=cEnd; i>=cStart; i--) {
                        matrix[rEnd][i] = now;
                        now++;
                    }
                }
                rEnd--;
                if (cStart<=cEnd) {
                    for(int i=rEnd; i>=rStart;i--) {
                        matrix[i][cStart] = now;
                        now++;
                    }
                }
                cStart++;

            }
            return matrix;
        }
};

int main () {
    Solution sl;
    vector<vector<int>> res = sl.generateMatrix(10);
    printMat(res);
}
