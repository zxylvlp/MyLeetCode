#include <vector>
#include <string>
#include "printHelper.hh"
using namespace std;
class Solution {
    public:
        vector<string> res;
        int n;
        vector<string> row;
        string s;
        vector<string> restoreIpAddresses(string s_) {
            s = s_;
            n = s_.size();
            backtrack(0);
            return res;
        }

        void backtrack(int i) {
            if (i==n && row.size()==4) {
                string s_;
                for (int j=0; j<3; j++)
                    s_ += row[j] + ".";
                s_ += row[3];
                res.push_back(s_);
                return;
            }

            if (row.size()>=4||(n-i)>(4-row.size())*3||(n-i)<(4-row.size())*1)
                return;

            if (s[i]=='0') {
                row.push_back("0");
                backtrack(i+1);
                row.pop_back();
            } else {
                for (int j=1; j<=3; j++) {
                    if (s.size()<i+j)
                        break;
                    string s_ = s.substr(i, j);
                    int num = stoi(s_);
                    if (num>255) {
                        break;
                    }
                    row.push_back(s_);
                    backtrack(i+j);
                    row.pop_back();
                }
            }
        }

};

int main(void) {
    Solution sl;
    //auto res = sl.restoreIpAddresses("25525511135");

    auto res = sl.restoreIpAddresses("1111");
    printVec(res);
}
