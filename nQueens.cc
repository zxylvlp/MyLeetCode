#include <vector>
#include "printHelper.hh"
using namespace std;

class Solution {
    public:
        vector<vector<string>> solveNQueens(int n) {
            vector<string> sl(n, string(n, '.'));
            vector<bool> colFlag(n, true);
            vector<bool> diaFlag(2*n-1, true);
            vector<bool> tDiaFlag(2*n-1, true);
            vector<vector<string>> res;
            solve(res, sl, colFlag, diaFlag, tDiaFlag, 0, n);
            return res;
        }

    private:
        void solve(vector<vector<string>> &res, vector<string> &sl, vector<bool> &colFlag, vector<bool> &diaFlag, vector<bool> &tDiaFlag, int row, int n) {
            if (row == n) {
                res.push_back(sl);
            }

            for (int col = 0; col != n; col++) {
                if (colFlag[col] && diaFlag[row+col] && tDiaFlag[n-1-(row-col)]) {
                    colFlag[col] = diaFlag[row+col] = tDiaFlag[n-1-(row-col)] = false;
                    sl[row][col] = 'Q';
                    solve(res, sl, colFlag, diaFlag, tDiaFlag, row+1, n);
                    sl[row][col] = '.';
                    colFlag[col] = diaFlag[row+col] = tDiaFlag[n-1-(row-col)] = true;
                }
            }
        }
};

int main(void) {
    Solution sl;
    vector<vector<string>> res = sl.solveNQueens(4);
    printMat(res);
}
