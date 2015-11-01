#include <vector>
using namespace std;
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int minPrice = INT_MAX;
            int profix = 0;
            for (int i=0; i<prices.size(); i++) {
                minPrice = min(prices[i], minPrice);
                profix = max(profix, (prices[i]-minPrice));
            }
            return profix;
        }
};

int main(void) {
    Solution sl;
}
