#include <unordered_map>
#include <vector>
#include <string>
#include "printHelper.hh"
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        sort(strs.begin(), strs.end());
        int idx=0;
        unordered_map<string,int> map;
        for (int i=0; i<strs.size(); i++) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if (map.count(tmp)) {
                res[map[tmp]].push_back(strs[i]);
            } else {
                map[tmp] = idx;
                idx++;
                res.push_back(vector<string>{strs[i]});
            }
        }
        return res;
        
    }
};

int main(void) {
    vector<string> vec{"eat", "tea", "tan", "ate", "nat", "bat"};
    printVec(vec);
    Solution sl;
    vector<vector<string>> res = sl.groupAnagrams(vec);
    printMat(res);
}
