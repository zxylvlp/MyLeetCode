#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            if (nums.empty())
                return 0;
            auto read=nums.begin()+1;
            auto write=nums.begin()+1;
            int count=1;
            for(; read<nums.end(); read++) {
                if (*read==*(read-1))
                    count++;
                else
                    count=1;
                if (count<=2) {
                    *write = *read;
                    write++;
                }
            }
            return write-nums.begin();

        }
};

int main(void) {
    Solution sl;
    vector<int> vec{1,1,1,2,2,3};
    cout << sl.removeDuplicates(vec) << endl;
}
