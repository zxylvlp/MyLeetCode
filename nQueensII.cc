#include <vector>
#include <iostream>
using namespace std;

class Solution {
    public:
        int totalNQueens(int n) {
            vector<bool> colFlag(n, true);
            vector<bool> diaFlag(2*n-1, true);
            vector<bool> tDiaFlag(2*n-1, true);
            int res = 0;
            solve(colFlag, diaFlag, tDiaFlag, 0, n, res);
            return res;
        }

    private:
        void solve(vector<bool> &colFlag, vector<bool> &diaFlag, vector<bool> &tDiaFlag, int row, int n, int &res) {
            if (row == n) {
                res++;
            }

            for (int col = 0; col != n; col++) {
                if (colFlag[col] && diaFlag[row+col] && tDiaFlag[n-1-(row-col)]) {
                    colFlag[col] = diaFlag[row+col] = tDiaFlag[n-1-(row-col)] = false;
                    solve(colFlag, diaFlag, tDiaFlag, row+1, n, res);
                    colFlag[col] = diaFlag[row+col] = tDiaFlag[n-1-(row-col)] = true;
                }
            }
        }
};

int main(void) {
    Solution sl;
    int res = sl.totalNQueens(4);
    cout << res << endl;
}
