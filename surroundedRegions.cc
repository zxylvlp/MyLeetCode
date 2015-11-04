#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include "printHelper.hh"
using namespace std;
class Solution {
    public:
        void solve(vector<vector<char>>& board) {
            int m = board.size();
            if (m<=2)
                return;
            int n = board.back().size();
            if (n<=2)
                return;

            for (int j=0; j<n; j++) {
                if (board[0][j]=='O') {
                    bfs(0, j, board);
                }
                if (board[m-1][j]=='O') {
                    bfs(m-1, j, board);
                }
            }
            for (int i=0; i<m; i++) {
                if (board[i][0]=='O') {
                    bfs(i, 0, board);
                }
                if (board[i][n-1]=='O') {
                    bfs(i, n-1, board);
                }
            }

            for (int i=0; i<m; i++) {
                for (int j=0; j<n; j++) {
                    if (board[i][j]=='O')
                        board[i][j] = 'X';
                    if (board[i][j]=='B')
                        board[i][j] = 'O';
                }
            }
        }
        void bfs(int i, int j, vector<vector<char>> &board) {
            queue<pair<int, int>> que;
            que.push(make_pair(i,j));
            board[i][j]='B';
            while (!que.empty()) {
                pair<int, int> q = que.front();
                que.pop();
                //printVec(board);
                if (q.first-1>=0&&board[q.first-1][q.second] == 'O') {

                    board[q.first-1][q.second]='B';
                    que.push(make_pair(q.first-1, q.second));
                }
                if (q.first+1<board.size()&&board[q.first+1][q.second] == 'O') {

                    board[q.first+1][q.second]='B';
                    que.push(make_pair(q.first+1, q.second));
                }
                if (q.second-1>=0&&board[q.first][q.second-1] == 'O') {
                    
                    board[q.first][q.second-1]='B';
                    que.push(make_pair(q.first, q.second-1));
                }
                if (q.second+1<board.back().size()&&board[q.first][q.second+1] == 'O') {

                    board[q.first][q.second+1]='B';
                    que.push(make_pair(q.first, q.second+1));
                }
            }
        }
};
int main(void) {
    Solution sl;
    vector<string> mat{"OOOOOOOOXOOOOOXOOOOO","OOOOOOOXOOOOOOOOOOOO","XOOXOXOOOOXOOXOOOOOO","OOOOOOOOOOOOOOOOOXXO","OXXOOOOOOXOOOOOOOOOO","OOOOXOOOOOOXOOOOOXXO","OOOOOOOXOOOOOOOOOOOO","OOOOOOOOOOOOOXOOOOOO","OOOOOOOOOOOOOOOOOOXO","OOOOOXOOOOOOOOOOOOOO","OOOOOOOOXOOOOOOOOOOO","OOOOXOOOOXOOOOOOOOOO","OOOOOOOOXOOOOOOOOOOO","XOOOOOOOOXXOOOOOOOOO","OOOOOOOOOOOXOOOOOOOO","OOOOXOOOOOOOOXOOOOOX","OOOOOXOOOOOOOOOXOXOO","OXOOOOOOOOOOOOOOOOOO","OOOOOOOOXXOOOXOOXOOX","OOOOOOOOOOOOOOOOOOOO"};
    //sl.solve(mat);
}
