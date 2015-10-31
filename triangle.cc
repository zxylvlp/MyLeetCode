#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> vec = triangle.back();
        for (int i=vec.size()-2; i>=0; i--) {
            for (int j=0; j<=i; j++) {
                vec[j] = triangle[i][j] + min(vec[j], vec[j+1]);
            }
        }
        return vec[0];
        
    }
};
int main(void) {
    Solution sl;
    vector<vector<int>> mat{vector<int>{2},
        vector<int>{3,4},
        vector<int>{6,5,7},
        vector<int>{4,1,8,3}
    };
    cout << sl.minimumTotal(mat) << endl;
}
