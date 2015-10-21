#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix,int target) {
            int m = matrix.size();
            int n = matrix.front().size();
            int l = 0;
            int r = m*n - 1;
            while(l<=r) {
                int mid = (l+r)>>1;
                int a = mid/n;
                int b = mid%n;
                if (matrix[a][b]<target)
                    l = mid+1;
                else if (matrix[a][b]==target)
                    return true;
                else
                    r = mid-1;
            }
            return false;
        }
};

int main(void) {
    vector<vector<int>> vec{ vector<int>{1,   3,  5,  7},
        vector<int>{10, 11, 16, 20},
        vector<int>{23, 30, 34, 50}};
    Solution sl;
    cout << sl.searchMatrix(vec,3) << endl;
}
