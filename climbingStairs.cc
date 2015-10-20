#include <iostream>
using namespace std;
class Solution {
    public:
        int climbStairs(int n) {
            if (n==0)
                return 0;
            int i=1;
            int oneNum = 1;
            int twoNum = 0;
            while(i<n) {
                int tmp = oneNum;
                oneNum = oneNum + twoNum;
                twoNum = tmp;
                i++;
            }
            return oneNum+twoNum;

        }
};

int main(void) {
    Solution sl;
    cout << sl.climbStairs(4) << endl;
}
