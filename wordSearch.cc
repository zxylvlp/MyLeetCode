#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
        vector<vector<char>> board;
        string word;
        int n;
        int m;
        int len;
        bool exist(vector<vector<char>>& board_, string word_) {
            m = board_.size();
            n = board_.front().size();
            board = board_;
            word = word_;
            len = word_.size();
            for (int i=0; i<m; i++) {
                for (int j=0; j<n; j++) {
                    if (backtrack(i, j, 0)) {
                        return true;
                    }
                }
            }
            return false;
        }

        bool backtrack(int i, int j, int k) {
            if (k==len)
                return true;
            bool res = false;
            if (i<0||i>=m||j<0||j>=n)
                return res;
            if (board[i][j]!=word[k])
                return res;
            board[i][j] = '\0';

            res = backtrack(i+1,j,k+1)
             || backtrack(i-1,j,k+1)
             || backtrack(i,j+1,k+1)
             || backtrack(i,j-1,k+1);
            board[i][j] = word[k];
            return res;
        }
};

int main(void) {
    Solution sl;
    vector<int> nums{1,2,3};
    vector<vector<char>> mat{vector<char>{'A', 'B', 'C', 'E'},
        vector<char>{'S', 'F', 'C', 'S'},
        vector<char>{'A', 'D', 'E', 'E'}};
    cout << sl.exist(mat, "ABCCED") << endl;
}
