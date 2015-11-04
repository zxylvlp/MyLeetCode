#include <vector>
using namespace std;
class UF {
    private:
        int *id; // id[i]=parent of i
        int *rank;
        int count;
    public:
        UF(int N) {
            count = N;
            id = new int[N];
            rank = new int[N];
            for (int i=0; i<N; i++) {
                id[i] = i;
                rank[i] = 0;
            }
        }

        ~UF() {
            delete[] id;
            delete[] rank;
        }

        int find(int p) {
            while (p!=id[p]) {
                id[p] = id[id[p]];
                p = id[p];
            }
            return p;
        }

        int getCount() {
            return count;
        }

        bool connected(int p, int q) {
            return find(p) == find(q);
        }

        void connect(int p, int q) {
            int i = find(p);
            int j = find(q);
            if (i==j)
                return;
            if (rank[i]<rank[j])
                id[i] = j;
            else if (rank[i]>rank[j])
                id[j] = i;
            else {
                id[j] = i;
                rank[i]++;
            }
            count--;
        }

};
class Solution {
    public:
        void solve(vector<vector<char>> &board) {
            int m = board.size();
            if (m==0)
                return;
            int n = board.back().size();
            UF uf(m*n+1);
            for (int i=0; i<m; i++) {
                for (int j=0; j<n; j++) {
                    if ((i==0||i==m-1||j==0||j==n-1)&&board[i][j]=='O')
                        uf.connect(i*n+j, m*n);
                    else if(board[i][j]=='O') {
                        if (board[i-1][j]=='O')
                            uf.connect(i*n+j, (i-1)*n+j);
                        if (board[i+1][j]=='O')
                            uf.connect(i*n+j, (i+1)*n+j);
                        if (board[i][j-1]=='O')
                            uf.connect(i*n+j, i*n+j-1);
                        if (board[i][j+1]=='O')
                            uf.connect(i*n+j, i*n+j+1);
                    }
                }
            }

            for (int i=0; i<m; i++) {
                for (int j=0; j<n; j++) {
                    if (!uf.connected(i*n+j, m*n))
                        board[i][j] = 'X';
                }
            }
        }
};
int main(void) {
    Solution sl;
}
