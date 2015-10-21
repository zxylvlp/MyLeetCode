#include <iostream>
#include "printHelper.hh"
using namespace std;

class Solution {

    public:
        void setZeroes(vector<vector<int>>& matrix) {
            int col0 = 1;
            int m = matrix.size();
            int n = matrix.front().size();

            for(int i=0; i<m; i++)
                if (matrix[i][0] == 0)
                    col0 = 0;

            for(int i=0; i<n; i++)
                if (matrix[0][i] == 0)
                    matrix[0][0] = 0;

            for(int i=1; i<m; i++)
                for(int j=1; j<n; j++)
                    if (matrix[i][j]==0)
                        matrix[i][0] = matrix[0][j] = 0;

            for(int i=1; i<m; i++)
                for(int j=1; j<n; j++)
                    if (matrix[i][0]==0||matrix[0][j]==0)
                        matrix[i][j]=0;

            if (matrix[0][0]==0)
                for(int i=0; i<n; i++)
                    matrix[0][i]=0;

            if (col0==0)
                for(int i=0; i<m; i++)
                    matrix[i][0]=0;
        }

};

int main(void) {
    Solution sl;
    vector<vector<int>> mat{vector<int>{1,0,1},vector<int>{1,1,1},vector<int>{1,1,1}};
    printMat(mat);
    sl.setZeroes(mat);
    cout << endl;
    printMat(mat);

}
