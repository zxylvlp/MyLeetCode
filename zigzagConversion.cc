#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {

	public:
		string convert(string s, int numRows) {
			if (numRows<=1) return s;
			vector<string> sArr(numRows);
			int row=0;
			int step=1;
			for (string::iterator iter=s.begin();iter!=s.end();iter++) {

				sArr[row].push_back(*iter);
				if (row==0) 
					step = 1;
				else if(row==numRows-1)
					step = -1;
				row = row + step;
			}
			s.clear();
			for (vector<string>::iterator iter=sArr.begin();iter!=sArr.end();iter++)
				s.append(*iter);
			return s;
		}
};
int main() {
	Solution solution;
	string s= "PAYPALISHIRING";
	int numRows = 3;
	cout<<solution.convert(s,numRows);
}
