#include <vector>
#include "printHelper.hh"
using namespace std;
class Solution {
    public:

        void rotate(vector<vector<int>>& matrix) {
            int size = matrix.size();
            if (size<=1)
                return;
            for(int i=0; i<size/2; i++) {
                for(int j=0; j<size; j++) {
                    swap(matrix[i][j], matrix[size-i-1][j]);
                }
            }

            //printMat(matrix);
            for(int i=0; i<size; i++) {
                for(int j=0; j<i; j++) {
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
            
        }
};

int main(void) {
    vector<int> vec1{1,2,3};
    vector<int> vec2{4,5,6};
    vector<int> vec3{7,8,9};
    vector<vector<int>> mat{vec1, vec2, vec3};
    printMat(mat);
    Solution sl;
    sl.rotate(mat);
    printMat(mat);
}
