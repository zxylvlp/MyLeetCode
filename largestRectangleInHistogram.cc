#include <vector>
#include <iostream>
using namespace std;

class Solution {
    public:
        int largestRectangleArea(vector<int>& height) {
            if (height.size()<=0) {
                return 0;
            }

            height.push_back(0);
            vector<int> stk;
            int maxArea = 0;
            for (int i=0; i<height.size();i++) {
                if (stk.empty() || height[i] >= height[stk.back()]) {
                    stk.push_back(i);
                    continue;
                } 
                int topIdx = stk.back();
                stk.pop_back();
                int area = height[topIdx] * (stk.size()==0?i:(i-stk.back()-1));
                if (area>maxArea)
                    maxArea = area;
                i--;
            }
            return maxArea;
        }
};

int main(void) {
    Solution sl;
    vector<int> vec{2,1,5,6,2,3};
    cout << sl.largestRectangleArea(vec) << endl;
}
