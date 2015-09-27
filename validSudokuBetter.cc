#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
	public:
		bool isValidSudoku(vector<vector<char>>& board) {
			int mapRow[9][9] = {0};
			int mapCol[9][9] = {0};
			int mapSub[9][9] = {0};
			cout << mapRow[8];
			for (int i=0; i<9; i++) {
				int tmpI = i-i%3;
				for (int j=0; j<9; j++) {
					int c = int(board[i][j]);
					if (c=='.')
						continue;
					if (c>'9'||c<'1')
						return false;
					c=c-'1';
					int tmp = tmpI+j/3;
					if (mapRow[i][c]||mapCol[j][c]||mapSub[tmp][c]) {
						return false;
					} 
					mapRow[i][c] = 1;
					mapCol[j][c] = 1;
					mapSub[tmp][c] = 1;
				}
			}
			return true;

		}
	
};

int main() {
	Solution sl;
	vector<char> r1{'1','2','3','4','5','6','7','8','9'};
	vector<vector<char>> board{r1};
	cout << sl.isValidSudoku(board) << endl;
}
