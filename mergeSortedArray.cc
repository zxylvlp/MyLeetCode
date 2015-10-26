#include <vector>
#include "printHelper.hh"
using namespace std;

class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            nums1.resize(m+n);
            int i = m-1;
            int j = n-1;
            int k = m+n-1;
            while (i>=0 && j>=0) {
                if (nums1[i]>nums2[j])
                    nums1[k--] = nums1[i--];
                else
                    nums1[k--] = nums2[j--];
            }
            while (j>=0) {
                nums1[k--] = nums2[j--];
            }

        }
};

int main(void) {
    Solution sl;
    vector<int> nums1{1,3,5};
    vector<int> nums2{2,4,6};
    sl.merge(nums1, 3, nums2, 3);
    printVec(nums1);
}
