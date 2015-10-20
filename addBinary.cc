#include <iostream>
#include <string>
using namespace std;
class Solution {
    public:
        string addBinary(string a, string b) {
            int i = a.size()-1;
            int j = b.size()-1;
            int c = 0;
            string res;
            while (i>=0||j>=0||c>=1) {
                if (i>=0)
                    c += a[i--]-'0';
                if (j>=0)
                    c += b[j--]-'0';
                char tmp = c % 2 + '0';
                c = c / 2;
                res = tmp + res;
            }
            return res;
        }
};

int main() {
    Solution sl;
    cout << sl.addBinary("111", "111") << endl;
}

