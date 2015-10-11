#include "printHelper.hh"
#include <vector>
using namespace std;
class Solution {
    public:
        vector<vector<int>> res;
        int end;
        void recursion(vector<int> num, int start) {
            if (start == end-1) {
                res.push_back(num);
                return;
            }
            for (int k=start; k<end; k++) {
                if (k!=start && num[k] == num[start])
                    continue;
                swap(num[start], num[k]);
                recursion(num, start+1);

            }

        }

        vector<vector<int>> permuteUnique(vector<int>& num) {
            sort(num.begin(), num.end());
            end = num.size();
            recursion(num, 0);
            return res;
        }
};


int main(void) {
    vector<int> vec{1,1,2};
    Solution sl;
    vector<vector<int>> res = sl.permuteUnique(vec);
    printMat(res);

}
