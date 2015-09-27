#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
	public:
		bool isValidSudoku(vector<vector<char>>& board) {
			unordered_map<char,bool> dict;
			return checkRow(board,dict)&&checkCol(board,dict)&&checkSub(board,dict);

		}
	private:
		bool checkRow(vector<vector<char>>& board,unordered_map<char,bool>& dict) {
			for (int i=0; i<9; i++) {
				for (int j=0; j<9; j++) {
					char c = board[i][j];
					if (c=='.')
						continue;
					if (c>'9'||c<'1')
						return false;
					if (dict[c]) {
						return false;
					} else {
						dict[c] = true;
					}
				}
				dict.clear();
			}
			return true;
		}
		bool checkCol(vector<vector<char>>& board,unordered_map<char,bool>& dict) {
			for (int i=0; i<9; i++) {
				unordered_map<char,bool> dict;
				for (int j=0; j<9; j++) {
					char c = board[j][i];
					if (c=='.')
						continue;
					if (c>'9'||c<'1')
						return false;
					if (dict[c]) {
						return false;
					} else {
						dict[c] = true;
					}
				}
				dict.clear();
			}
			return true;

		}
		bool checkSub(vector<vector<char>>& board,unordered_map<char,bool>& dict) {
			for (int i=0; i<9; i+=3) {
				for (int j=0; j<9; j+=3) {
					unordered_map<char,bool> dict;
					for (int k=0; k<3; k++) {
						for (int l=0; l<3; l++) {
							char c = board[i+k][j+l];
							if (c=='.')
								continue;
							if (c>'9'||c<'1')
								return false;
							if (dict[c]) {
								return false;
							} else {
								dict[c] = true;
							}

						}
					}
					dict.clear();
				}
			}
			return true;
		}
};
int main() {
	Solution sl;
	vector<char> r1{'1','2','3','4','5','6','7','8','9'};
	vector<vector<char>> board{r1};
	//cout << sl.isValidSudoku(board) << endl;
}
