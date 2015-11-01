#include <vector>
using namespace std;
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            if (prices.size() <= 1)
                return 0;
            vector<int> t(prices.size(), 0);
            for (int i=1; i<=2; i++) {
                int tmpMax = t[0] - prices[0];
                for (int j=1; j<prices.size(); j++) {
                    tmpMax = max(tmpMax, t[j] - prices[j]);
                    t[j] = max(t[j-1], prices[j]+tmpMax);

                }
            }
            return t[prices.size()-1];
        }
};
int main(void) {
    Solution sl;
}
