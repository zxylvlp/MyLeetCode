#include <vector>
class Solution {
public:
    int n;
    vector<vector<string>> res;
    vector<vector<string>> parition(string s) {
        n = s.size();

        backtrack(0);
        
    }
    void backtrack(int i) {
        for (int j=i; j<n; j++) {

        }

    }
};
int main(void) {
    Solutin sl;
}
