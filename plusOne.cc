#include <iostream>
#include <vector>
#include "printHelper.hh"
using namespace std;

class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {
            int n = digits.size()-1,i;
            for(i=n; i>=0; i--) {
                if (digits[i] == 9) {
                    digits[i] = 0;
                } else {
                    digits[i] += 1;
                    break;
                }
            }
            if (i==-1) {
                digits[0] = 1;
                digits.push_back(0);
            }
            return digits;
        }
};

int main(void) {
    Solution sl;
    vector<int> digits{9,9,9};
    printVec(digits);
    vector<int>res = sl.plusOne(digits);
    printVec(res);
}
