#include <vector>
#include "printHelper.hh"
using namespace std;
class Solution {
    public:
        vector<vector<int>> generate(int numRows) {
            vector<vector<int>> res;
            if (numRows<1) {
                return res;
            }
            res.push_back(vector<int>(1, 1));
            for(int i=1; i<numRows; i++) {
                res.push_back(vector<int>(1, 1));
                for(int j=0; j<res[i-1].size()-1; j++) {
                    res[i].push_back(res[i-1][j]+res[i-1][j+1]);
                }
                res[i].push_back(1);
            }
            return res;
        }
};

int main(void) {
    Solution sl;
    auto res = sl.generate(5);
    printMat(res);
}
