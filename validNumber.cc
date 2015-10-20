#include <iostream>
#include <string>
using namespace std;
class Solution {
    public:
        bool isNumber(string s) {
            int i = 0;
            for(; s[i] == ' '; i++) {
            }
            if (s[i] == '+' || s[i] == '-')
                i++;
            int nNum, nPt;
            for (nNum=0, nPt=0; (s[i]<='9' && s[i]>='0') || s[i]=='.'; i++)
                (s[i]=='.') ? nPt++:nNum++;

            if (nPt>1||nNum<1)
                return false;

            if (s[i]=='e') {
                i++;
                if (s[i] == '+' || s[i] == '-')
                    i++;
                for (nNum=0; (s[i]<='9' && s[i]>='0'); i++)
                    nNum++;
                if (nNum<1)
                    return false;
            }

            for(; s[i] == ' '; i++) {
            }

            return s[i] == '\0';
        }
};

int main(void) {
    Solution sl;
    cout << sl.isNumber("1e15") << endl;
}
