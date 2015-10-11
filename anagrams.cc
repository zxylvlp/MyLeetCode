#include <unorder_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unorder_map map;
        for (int i=0; strs.size(); i++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            if (map.count(str)>0) {
                map[str].push_back(strs[i]);
            } else {
                map[str] = vector<int>();
            }
        }
        unorder_map map
    }
};

int main(void) {
    Solution sl;
    sl.groupAnagrams();
}
