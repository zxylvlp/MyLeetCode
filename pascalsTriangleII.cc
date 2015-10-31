#include <vector>
#include "printHelper.hh"
using namespace std;
class Solution {
    public:
        vector<int> getRow(int rowIndex) {
            vector<int> res(rowIndex+1, 1);
            for (int i=2; i<=rowIndex; i++) {
                for (int j=(rowIndex-i+1); j<rowIndex; j++) {
                    res[j] = res[j] + res[j+1];
                }
            }
            return res;
            
        }
};

int main(void) {
    Solution sl;
    auto res = sl.getRow(3);
    printVec(res);
}

