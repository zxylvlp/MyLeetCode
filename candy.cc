#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n<=1)
            return n;
        vector<int> vec(n, 1);
        for (int i=0; i<n-1; i++) {
            if (ratings[i] < ratings[i+1]) {
                vec[i+1] = vec[i]+1;
            }
        }
        for (int i=n-2; i>=0; i--) {
            if (ratings[i] > ratings[i+1]) {
                vec[i] = max(vec[i+1] + 1, vec[i]);
            }
        }
        int res=0;
        for (int i=0; i<n; i++) {
            res+=vec[i];
        }
        return res;
    }
};
int main(void) {
    Solution sl;
}
