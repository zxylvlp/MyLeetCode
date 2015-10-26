#include <vector>
#include "printHelper.hh"
using namespace std;

class Solution {
    public:
        vector<int> grayCode(int n) {
            vector<int> res(1, 0);
            for (int i=0; i<n; i++) {
                int add = 1<<i;
                for (int j=res.size()-1; j>=0; j--) {
                    int val = res[j];
                    val += add;
                    res.push_back(val);
                }
            }
            return res;

        }
};

int main(void) {
    Solution sl;
    vector<int>res = sl.grayCode(2);
    printVec(res);
}
