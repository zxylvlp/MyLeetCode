#include <iostream>
#include <string>
using namespace std;
class Solution {
    public:
        int numDecodings(string s) {
            int n = s.size();
            if (n<=0||s[0]=='0') {
                return 0;
            }
            
            int one = 1;
            int two = 0;
            for (int i=1; i<n; i++) {
                if (s[i-1]=='1' ||(s[i-1]=='2' && s[i]<='6' && s[i]>='0')) {
                    if (s[i]!='0') {
                        int tmp = one + two;
                        two = one;
                        one = tmp;
                    } else {
                        two = one;
                        one = 0;
                    }
                    
                } else if (s[i]!='0') {
                    one += two;
                    two = 0;
                } else {
                    return 0;
                }
            }
            return one+two;
        }
};

int main(void) {
    Solution sl;
    cout << sl.numDecodings("123123") << endl;
}
