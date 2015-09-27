#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		void solveSudoku(vector<vector<char>>& board_) {
			board = board_;
			solve(0, 0);
			board_ = board;
			
		}
	private:
		vector<vector<char>> board;
		bool solve(int i, int j) {
			for (; i<9; i++) {
				for (; j<9; j++) {
					char c = board[i][j];
					if(c=='.') {
						for (char k='1'; k<= '9'; k++) {
							if (valid(i, j, k)) {
								board[i][j] = k;
								
							    if (solve(i, (j+1)))
										return true;
							}
						}
						board[i][j] = '.';
						return false;
					}
				}
				j=0;

			}
			return true;


		}
		bool valid(int i, int j, char c) {
			for (int row=0; row<9; row++) {
				if (c == board[row][j]) {
					return false;
				}

			}
			for (int col=0; col<9; col++) {
				if (c == board[i][col]) {
					return false;
				}

			}
			int tmpI = i-i%3;
			int tmpJ = j-j%3;
			for (int row=tmpI; row<tmpI+3; row++) {
				for (int col=tmpJ; col<tmpJ+3; col++) {
					if (c == board[row][col]) {
						return false;
					}
				}

			}
			return true;
		}

};

int main() {
	Solution sl;

}
