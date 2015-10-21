#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
    public:
        int minDistance(string word1, string word2) {
            int m = word1.size();
            int n = word2.size();
            vector<int> tab(n+1, 0);
            for (int i=1; i<=n; i++)
                tab[i] = i;

            for (int i=1; i<=m; i++) {
                int prev = i;
                for (int j=1; j<=n; j++) {
                    int cur;
                    if (word1[i-1]==word2[j-1]) {
                        cur = tab[j-1];
                    } else {
                        cur = min(min(prev,tab[j]),tab[j-1]) + 1;
                    }
                    tab[j-1] = prev;
                    prev = cur;
                }
                tab[n] = prev;
            }
            return tab[n];
        }
};

int main(void) {
    Solution sl;
    cout << sl.minDistance("abc", "cba") << endl;
}
