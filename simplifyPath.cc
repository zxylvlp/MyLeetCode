#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "printHelper.hh"
using namespace std;

class Solution {
    public:
        string simplifyPath(string path) {
            stringstream ss;
            int pos = 0;
            vector<string> stk;
            if (path.back()!='/')
                path += '/';
            while(pos!=path.size()-1) {
                int nextPos= path.find('/', pos+1);
                string str = path.substr(pos+1,nextPos-pos-1);
                pos = nextPos;
                if (str==""||str==".") {
                    continue;
                } else if (str=="..") {
                    if (stk.size()>0) {
                        stk.pop_back();
                    }
                } else {
                    stk.push_back(str);
                }
            }
            if (stk.empty())
                return "/";
            for(int i=0; i<stk.size();i++) {
                ss << "/";
                ss << stk[i];
            }
            string res;
            ss >> res;
            return res;
        }
};

int main(void) {
    Solution sl;
    cout << sl.simplifyPath("/a/./b/../../c/") << endl;
}
