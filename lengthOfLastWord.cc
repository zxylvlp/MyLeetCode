#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int rStart = s.find_last_not_of(' ');
        if (rStart==-1) {
            return 0;
        } else if (rStart==0) {
            return 1;
        }
        return rStart - s.rfind(' ', rStart-1);
    }
};

int main(void) {
    Solution sl;
    cout << sl.lengthOfLastWord("a ") << endl;
}
