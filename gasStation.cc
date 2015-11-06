#include <vector>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank=0, total=0, pos=0;
        for (int i=0; i<gas.size(); i++) {
            tank = tank + gas[i] - cost[i];
            if (tank<0) {
                total = total+tank;
                tank = 0;
                pos = i+1;
            }

        }
        return total+tank<0? -1 : pos;
        
    }
};
int main(void) {
    Solution sl;
}
