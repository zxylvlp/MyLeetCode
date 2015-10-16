#include <vector>
#include "printHelper.hh"
using namespace std;

class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> res;
            if (matrix.size()==0) {
                return res;
            }
            int rEnd = matrix.size()-1;
            int cEnd = matrix[0].size()-1;
            int rStart = 0;
            int cStart = 0;
            while (rStart<=rEnd && cStart<=cEnd) {
                for (int i=cStart; i<=cEnd; i++) {
                    res.push_back(matrix[rStart][i]);
                }
                rStart++;
                for (int i=rStart; i<=rEnd; i++) {
                    res.push_back(matrix[i][cEnd]);
                }
                cEnd--;
                if (rStart<=rEnd) {
                    for(int i=cEnd; i>=cStart; i--) {
                        res.push_back(matrix[rEnd][i]);
                    }
                }
                rEnd--;
                if (cStart<=cEnd) {
                    for(int i=rEnd; i>=rStart;i--) {
                        res.push_back(matrix[i][cStart]);
                    }
                }
                cStart++;

            }
            return res;
        }
};

int main () {
    vector<int> row1{2,3};
    vector<vector<int>> mat{row1};
    Solution sl;
    vector<int> res = sl.spiralOrder(mat);
    printVec(res);

}
