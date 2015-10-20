#include <iostream>
using namespace std;

class Solution {
    public:
        int mySqrt(int x) {
            int left = 1, right = x, ans=0;
            while(left<=right) {
                int mid = (left + right)/2;
                if (mid<=x/mid) {
                    left = mid + 1;
                    ans = mid;
                } else {
                    right = mid-1;
                }
            }
            return ans;
        }
};

int main(void) {
    Solution sl;
    cout << sl.mySqrt(9) << endl;
}
